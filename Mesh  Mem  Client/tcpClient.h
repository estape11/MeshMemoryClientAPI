//
// Created by jeanpolalvarado on 09/09/16.
//

#ifndef MESH_MEMORY_TCPCLIENT_H
#define MESH_MEMORY_TCPCLIENT_H
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include "iostream"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdint.h>
#include "../rapidjson/include/rapidjson/document.h"

using namespace std;
using namespace rapidjson;
class tcpClient {
    int num;
public:
    tcpClient (int pnum){
        num=pnum;
    }
    void init();

};


#endif //MESH_MEMORY_TCPCLIENT_H
