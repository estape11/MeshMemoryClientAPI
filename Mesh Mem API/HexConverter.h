//
// Created by jeanpolalvarado on 08/09/16.
//



#ifndef MESH_MEMORY_HEXCONVERTER_H
#define MESH_MEMORY_HEXCONVERTER_H
#include <iostream>
#include<sstream>
#include <iomanip>

using namespace std;

class HexConverter {
    //Variables Importantes
    string instr,hexstr;
private:
    //Variable privada
    int num;
public:
    //Constructores
    HexConverter (int pnum){
        num=pnum;
        instr="";
        hexstr="";
    }
    HexConverter(string pstr){
        num=0;
        instr=pstr;
        hexstr="";}
    //Metodos de la clase HexConverter

    string intToHexString();
    string StringToHex();
    int intStringToHex();
    string hexToString();
    int hexCharToInt(char a);
    const string &getStr() const;
    void setStr(const string &str);
    int getNum() const;
    void setNum(int num);
    const string &getHexstr() const;
    void setHexstr(const string &hexstr);
};


#endif //MESH_MEMORY_HEXCONVERTER_H
