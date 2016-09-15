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
class xReference {
    //Atributos
    string ID;
    // Identifica el espacio de memoria dentro del Mesh Memory
    int size;           // El   tamaño   del   dato   almacenado
    xType type;         // Tipo de dato almacenado
    int* value=NULL;   // Apuntador al espacio de memoria que con el valor por copiar

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
    xReference (int psize, int* pvalue){
        size=psize;
        value=pvalue;
        UUID pid= UUID();
        ID=pid.getUUID();}
//metodos
    bool operator ==(const xReference& refer) const ; // refer es una instancia cualquiera d xReference
    bool operator !=(const xReference& refer) const ;
    int operator *()const ;
    //void operator =();
    int getSize() const;
    void setSize(int size);
    xType getType() const;
    void setType(xType type);
    void *getValue() const;
    void setValue(int *value);
    const string &getID() const;
    void setID(const string &ID);

};

#endif //MESH_MEMORY_XREFERENCE_H
