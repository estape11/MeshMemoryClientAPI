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

using namespace std;
using namespace rapidjson;

class API {
//private:
    char* host;
    int port;
    char xType;
    string token;
    Client cliente;

public:
    API(){
        cliente=Client();
    }
    char* initialize(string host, int port);
    xReference xMalloc(int size); //(int size, xType type);
    xReference xMalloc(int size,int* value); //apuntador   al   espacio   de   memoria   que   con ene el valor por copiar.
    void xFree(xReference toFree); //Contacta a Mesh Mem Manager para liberar el espacio indicado por toFree
    void xAssign(xReference reference,void* value);//Asigna el valor al espacio apuntado por reference  .

};

#endif //MESH_MEMORY_API_H
