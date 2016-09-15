//
// Created by jeanpolalvarado on 04/09/16.
//

#include "API.h"


xReference API::xMalloc(int size){
    int po=size;
    int* ptr= &po;
    xReference temp (90,ptr);
    return temp;
}
xReference API::xMalloc(int size, int* value) {
    xReference temp (size,value);
    return temp;
}
void API::xAssign(xReference reference, void *value) {}
void API::xFree(xReference toFree) {}
char* API::initialize(char* host, int port) {}
