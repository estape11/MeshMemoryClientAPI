//
// Created by jeanpolalvarado on 09/09/16.
//

#ifndef MESH_MEMORY_TCPSERVER_H
#define MESH_MEMORY_TCPSERVER_H

#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros

#define TRUE   1
#define FALSE  0
#define PORT 8888

class tcpServer {
    int num;
public:
    tcpServer (int pnum){
        num=pnum;
    }
    void init();

};

#endif //MESH_MEMORY_TCPSERVER_H
