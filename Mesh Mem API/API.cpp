//
// Created by jeanpolalvarado on 04/09/16.
//

#include "API.h"
#include "../rapidjson/include/rapidjson/stringbuffer.h"
#include "../rapidjson/include/rapidjson/writer.h"

using namespace rapidjson;

//INTEGER=0,LONG=1,FLOAT=2,SHORT=3,STRING=4,CHAR=5

/**
 * Constructor
 * @return void
 */
API::API(){
    cliente=Client();
}

/**
 * Conect to the manager using the IP and the Port
 * @param host
 * @param port
 * @return the token
 */
string API::initialize(string host, int port) {
    cliente.setConnection(host,to_string(port)); //inicio la conexion
    xToken();//genero el token
    return token;
}

/**
 * Generates the token if its the first conection or the token doesnt work
 */
void API::xToken() {
    StringBuffer jsonMsg;
    Writer<StringBuffer> writer(jsonMsg);
    writer.StartObject();
    writer.String("remitente");writer.String("cliente");
    writer.String("funcion");writer.String("token");
    writer.EndObject();
    cliente.writeData(jsonMsg.GetString());
    string respuesta=cliente.read2(); //recibe el token
    Document jsonMSG; //parseador
    jsonMSG.ParseInsitu((char*)respuesta.c_str()); //lo parsea
    token=jsonMSG["token"].GetString(); //lo utilizo como JsonObject
    globalToken=&token;
}

/**
 * Allocate memory space in the manager
 * @param size
 * @param type
 * @return the reference
 */
xReference API::xMalloc(int size, xType type) {
    StringBuffer jsonMsg;
    Writer<StringBuffer> writer(jsonMsg);
    writer.StartObject();
    writer.String("remitente");writer.String("cliente");
    writer.String("funcion");writer.String("xMalloc");
    writer.String("type");writer.Int((int)type);
    writer.String("bytes");writer.Int(size);
    writer.String("token");writer.String(token.c_str());
    writer.EndObject();
    cliente.writeData(jsonMsg.GetString());
    string respuesta=cliente.read2();
    string status;
    Document jsonMSG;
    jsonMSG.ParseInsitu((char*)respuesta.c_str());
    status=jsonMSG["funcion"].GetString();
    if(status=="error"){
        int error=jsonMSG["error"].GetInt();
        switch(error){
            case 1: {
                cout << "No existe el token en la lista del manager" << endl;
                xToken(); //solicito nuevo token
                break;
            }
            case 2:{
                cout<<"El token expiró"<<endl;
                xToken(); //solicito nuevo token
                break;
            }
            case 3:{
                cout<<"No hay memoria"<<endl;
                break;
            }
        }
    }
    else{
        xReference refer=xReference(status,size,type);
        return refer;
    }
}

/**
 * Assign the value of the pointer value and then send to the manager the reference (UUID) to set the value
 * @param reference
 * @param value
 */
void API::xAssign(xReference reference, void* value) {
    string base64Value=getValueAsBase64(reference, value);
    StringBuffer jsonMsg;
    Writer<StringBuffer> writer(jsonMsg);
    writer.StartObject();
    writer.String("remitente");writer.String("cliente");
    writer.String("funcion");writer.String("asignar");
    writer.String("UUID");writer.String(reference.getID().c_str());
    writer.String("value");writer.String(base64Value.c_str());
    writer.String("token");writer.String(token.c_str());
    writer.EndObject();
    cliente.writeData(jsonMsg.GetString());
}

/**
 * Relase the memory of the reference
 * @param toFree
 */
void API::xFree(xReference toFree) {
    //release the memory in the manager
}

string API::getToken() {
    return token;
}

/**
 * Identify wich value was and then decode to base 64
 * @param reference instance of xReference, gets the type using the xType enum
 * @param value of void pointer
 * @return string of the value converted in base64
 */
string API::getValueAsBase64(xReference reference, void *value) {
    int num = reference.getType();
    int numValue;
    long longValue;
    float floatValue;
    short shortValue;
    char charValue;
    string stringValue;
    string base64;
    switch (num){
        case 0:{
            numValue=*((int*)value);
            base64= encode((to_string(numValue)));
            break;
        }
        case 1:{
            longValue=*((long*)value);
            base64= encode((to_string(longValue)));
            break;
        }
        case 2:{
            floatValue=*((float *)value);
            base64= encode((to_string(floatValue)));
            break;
        }
        case 3:{
            shortValue=*((short *)value);
            base64= encode((to_string(shortValue)));
            break;
        }
        case 4:{
            charValue=*((char*)value);
            base64= encode((to_string(charValue)));
            break;
        }
        case 5:{
            stringValue=*((string*)value);
            base64= encode(stringValue);
            break;
        }
    }
    return base64;
}
