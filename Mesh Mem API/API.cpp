//
// Created by jeanpolalvarado on 04/09/16.
//

#include "API.h"
#include "../rapidjson/include/rapidjson/stringbuffer.h"
#include "../rapidjson/include/rapidjson/writer.h"

using namespace rapidjson;

//INTEGER=0,LONG=1,FLOAT=2,SHORT=3,STRING=4,CHAR=5,ARRAY=6

xReference API::xMalloc(int size, xType type) {
    StringBuffer jsonMsg;
    Writer<StringBuffer> writer(jsonMsg);
    writer.StartObject();
    writer.String("remitente");
    writer.String("cliente");
    writer.String("funcion");
    writer.String("xMalloc");
    writer.String("type");
    writer.Int((int)type);
    writer.String("bytes");
    writer.Int(size);
    writer.EndObject();
    string output= jsonMsg.GetString();
    cliente.writeData(output);
    string respuesta=cliente.read2();
    string status;
    const char* mensaje1=respuesta.c_str();
    Document doc;
    doc.ParseInsitu((char*)mensaje1);
    status=doc["UUID"].GetString();

    if(status=="no espacio"){
        xReference refer=xReference(NULL,size,type);
        return refer;
    }
    else{
        xReference refer=xReference(status,size,type);
        return refer;
    }

}

void API::xAssign(xReference reference, void* value) {}

void API::xFree(xReference toFree) {}

string API::initialize(string host, int port) {
    StringBuffer jsonMsg;
    Writer<StringBuffer> writer(jsonMsg);
    writer.StartObject();
    writer.String("remitente");
    writer.String("cliente");
    writer.String("funcion");
    writer.String("token");
    writer.EndObject();
    string output= jsonMsg.GetString();
    cliente.setConnection(host,to_string(port));
    cliente.writeData(output);
    string respuesta=cliente.read2(); //recibe el token
    const char* mensaje1=respuesta.c_str();
    Document doc;
    doc.ParseInsitu((char*)mensaje1);
    token=doc["token"].GetString();
    return token;
}