//
// Created by alecm on 10/09/16.
//

#ifndef MESH_MEMORY_UUID_H
#define MESH_MEMORY_UUID_H
#include <memory>
#include <iostream>

using namespace std;

class UUID {

public:
    //Constructor
    UUID(){}
    //Metodos
    string sendGetCmd(const char* cmd);
    string getUUID();
};

#endif //MESH_MEMORY_UUID_H
