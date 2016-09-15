//
// Created by jeanpolalvarado on 04/09/16.
//
#ifndef MESH_MEMORY_API_H
#define MESH_MEMORY_API_H
#include <iostream>
#include <stdio.h>
#include "xReference.h"
#include "xType.h"

using namespace std;

class API {
    char* host;
    int port;
    char xType;

public:
    API(){}
    char* initialize(char* host, int port);
    xReference xMalloc(int size); //(int size, xType type);
    xReference xMalloc(int size,int* value); //apuntador   al   espacio   de   memoria   que   con ene el valor por copiar.
    void xFree(xReference toFree); //Contacta a Mesh Mem Manager para liberar el espacio indicado por toFree
    void xAssign(xReference reference,void* value);//Asigna el valor al espacio apuntado por reference  .

};

#endif //MESH_MEMORY_API_H
