//
// Created by jeanpolalvarado on 04/09/16.
//
#ifndef MESH_MEMORY_API_H
#define MESH_MEMORY_API_H
#include <iostream>
#include <stdio.h>
#include "xReference.h"
#include "xType.h"
#include "../rapidjson/include/rapidjson/rapidjson.h"
#include "../rapidjson/include/rapidjson/document.h"
#include "../Mesh  Mem  Client/Client.h"
#include "iostream"
#include "string"
#include "base64.h"

using namespace std;
using namespace rapidjson;
static Client cliente=Client();
static string* globalToken=new string;
static string send(string dato){
    cliente.writeData(dato);
    string respuesta=cliente.read2();
    return respuesta;
}
class API {
private:
    string token;
public:
    API();
    string initialize(string host, int port);
    void xToken();
    xReference xMalloc(int size, xType type);
    //xReference xMalloc(int size, xType value);
    void xFree(xReference toFree);
    void xAssign(xReference reference,void* value);
    string getValueAsBase64(xReference reference,void* value);
    string getToken();
    void* xDereference(xReference reference);
};

#endif //MESH_MEMORY_API_H
