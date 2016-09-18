//
// Created by jeanpolalvarado on 04/09/16.
//
#ifndef MESH_MEMORY_XREFERENCE_H
#define MESH_MEMORY_XREFERENCE_H
#include <iostream>
#include <stdio.h>
#include "xType.h"
#include "../rapidjson/include/rapidjson/document.h"
#include <resolv.h>
#include "UUID.h"

using namespace std;
//template <class T>
class xReference {
    //Atributos
    string ID;
    // Identifica el espacio de memoria dentro del Mesh Memory
    int size;           // El   tamaño   del   dato   almacenado
    int type;         // Tipo de dato almacenado

public:
    //constructores
    /*
    xReference (int psize,xType ptype, int* pvalue){
        size=psize;
        value=pvalue;
        type= ptype;
        UUID pid= UUID();
        ID=pid.getUUID();
    }
*/
    xReference (string id, int psize, int ptype ){
        size=psize;
        ID=id;
        type=ptype;
    }

//metodos
    bool operator ==(const xReference& refer) const ; // refer es una instancia cualquiera d xReference
    bool operator !=(const xReference& refer) const ;
    int operator *()const ;
    //void operator =();
    int getSize() const;
    void setSize(int size);
    int getType() const;
    void setType(xType type);
    const string &getID() const;
    void setID(const string &ID);

};

#endif //MESH_MEMORY_XREFERENCE_H
