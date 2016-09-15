//
// Created by jeanpolalvarado on 04/09/16.
//

#include "API.h"
#include "../rapidjson/include/rapidjson/stringbuffer.h"
#include "../rapidjson/include/rapidjson/writer.h"

using namespace rapidjson;
xReference xMallocAPI (int size){
    int po=size;
    int* ptr= &po;
    xReference temp (90,ptr);
    return temp;
}
xReference API::xMalloc(int size, int* value) {
    xReference temp (size,value);
    return temp;
}
void API::xAssign(xReference reference, void *value) {}
void API::xFree(xReference toFree) {}
char* API::initialize(string host, int port) {
    StringBuffer jsonMsg;
    Writer<StringBuffer> writer(jsonMsg);
    writer.StartObject();
    writer.String("remitente");
    writer.String("cliente");
    writer.String("funcion");
    writer.String("token");
    writer.EndObject();
    cout<<jsonMsg.GetString()<<endl;
    string output= jsonMsg.GetString();
    cliente.setConnection(host,to_string(port));
    cliente.writeData(output);
    string mensaje=cliente.read2();//bienvenida
    string respuesta=cliente.read2();
    cout<<respuesta<<endl;
    const char* mensaje1=respuesta.c_str();
    Document doc;
    doc.ParseInsitu((char*)mensaje1);
    string token;
    if(doc.IsObject()){
        if(doc.HasMember("token")){
            if (doc["token"].IsString()){
                token=doc["token"].GetString();
            }
        }
    }
    cout<<token<<endl;
    return (char *) 'h';
}
