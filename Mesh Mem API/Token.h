//
// Created by jeanpolalvarado on 08/09/16.
//

#ifndef MESH_MEMORY_TOKEN_H
#define MESH_MEMORY_TOKEN_H
#include <iostream>
#include<sstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <random>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n
using namespace std;

class Token {
    //Atributo
    string token;
public:
    //Constructor
    Token(){}
    //Metodos
    string generateToken();
    const string &getToken() const;
    void setToken();
};


#endif //MESH_MEMORY_TOKEN_H
