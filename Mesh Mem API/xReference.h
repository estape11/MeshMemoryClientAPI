//
// Created by jeanpolalvarado on 04/09/16.
//
#ifndef MESH_MEMORY_XREFERENCE_H
#define MESH_MEMORY_XREFERENCE_H

#include <iostream>
#include <stdio.h>
#include "xType.h"

using namespace std;

//template<class tipo>
class xReference {
private:
    string ID;
    int size;
    xType type;
public:
    xReference(string pID, int psize, xType ptype){
        size=psize;
        type= ptype;
        ID=pID;
    }
    void* operator *()const ;
    bool operator ==(const xReference& refer) const ;
    bool operator !=(const xReference& refer) const ;
    xReference & operator=(const xReference &rhs);
    int getSize() const;
    void setSize(int size);
    int getType() const;
    void setType(xType);
    const string &getID() const;
    void setID(const string &ID);
    void setData(void* valor);
};

#endif //MESH_MEMORY_XREFERENCE_H
