//
// Created by jeanpolalvarado on 13/09/16.
//

#ifndef MESH_MEMORY_CLIENT_H
#define MESH_MEMORY_CLIENT_H
#include "stdio.h"
#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <thread>

using namespace std;

class Client {
    //Variables importantes del cliente
    int sock, portno, n;
    struct sockaddr_in ip_adress;
    struct hostent* server;
    char* buffer[256];
public:
    //Constructor
    Client(){}
    //Metodos de la clase Client
    void setConnection(string ip, string port);
    void setVariables();
    bool writeData(string data);
    string readData();
    string read2();
};


#endif //MESH_MEMORY_CLIENT_H
