//
// Created by jeanpolalvarado on 04/09/16.
//

#include "API.h"
#include "../rapidjson/include/rapidjson/stringbuffer.h"
#include "../rapidjson/include/rapidjson/writer.h"

using namespace rapidjson;

xReference API::xMalloc(int size, int type) {
    StringBuffer jsonMsg;
    Writer<StringBuffer> writer(jsonMsg);
    writer.StartObject();
    writer.String("remitente");
    writer.String("cliente");
    writer.String("funcion");
    writer.String("xMalloc");
    writer.String("type");
    writer.Int(type);
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
    if(doc.IsObject()){
        if (doc.HasMember("UUID")){
            if(doc["UUID"].IsString()){
                status=doc["UUID"].GetString();
            }
        }
    }

    if(status=="no espacio"){
        xReference refer=xReference(NULL,size,type);
        return refer;
    }
    else{
        xReference refer=xReference(status,size,type);
        return refer;
    }

}

Document API::getJson(string json){
    const char* mensaje1=json.c_str();
    Document doc;
    doc.ParseInsitu((char*)mensaje1);
    return doc;
}

void API::xAssign(xReference reference, void *value) {}

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
    string token;
    const char* mensaje1=respuesta.c_str();
    Document doc;
    doc.ParseInsitu((char*)mensaje1);
    if(doc.IsObject()){
        if (doc.HasMember("token")){
            if(doc["token"].IsString()){
                token=doc["token"].GetString();
            }
        }
    }
    return token;
}
