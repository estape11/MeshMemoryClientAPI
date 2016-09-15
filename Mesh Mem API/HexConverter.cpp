//
// Created by jeanpolalvarado on 08/09/16.
//

#include "HexConverter.h"

/**
 * Convierte Integer a un String en formato Hexadecimal
 * @return String en formato Hexadecimal
 */
string HexConverter::intToHexString() {
    int intValue=getNum();
    string hexStr;
    stringstream sstream;
    sstream << "0x"
            << std::setfill ('0') << std::setw(2)
            << std::hex << (int)intValue;
    hexStr= sstream.str();
    cout<<hexStr<<endl;
    sstream.clear();    //clears out the stream-string
    cout<<hexStr<<endl;
    return hexStr;
}
/**
 * Convierte
 * @return
 */
int HexConverter::intStringToHex() {
    char s[] = "0x0c";
    unsigned long x;
    x = strtoul(s, 0, 16);
    return x;
}
/**
 * Convierte un char a int
 * @param char a convertir
 * @return Retorna el char convertido a int
 */
int HexConverter::hexCharToInt(char a) {
    if(a>='0' && a<='9')
        return(a-48);
    else if(a>='A' && a<='Z')
        return(a-55);
    else
        return(a-87);
}

/**
 * COnvierte un Hexadecimal a String
 * @return Retorna un String que representa el Valor del Hexadecimal
 */
string HexConverter::hexToString() {
    string str=getHexstr();
    stringstream HexString;
    for(int i=0;i<str.length();i++){
        char a = str.at(i++);
        char b = str.at(i);
        int x = hexCharToInt(a);
        int y = hexCharToInt(b);
        HexString << (char)((16*x)+y);
    }
    return HexString.str();
}
/**
 * Convierte un String a base Hexadeciaml
 * @return Retorna un String
 */
string HexConverter::StringToHex() {
    string str =getStr() ;
    stringstream str1;
    int po = 12;
    for (int i = 0; i < str.length(); i++) {
        str1 << std::hex << (int) str.at(i);
    }
    cout << str1.str() << "\n";
    hexstr=str1.str();
    return str1.str();
}


///////////////////GETERS/SETTERS////////////////////////////////
const string &HexConverter::getStr() const {return instr;}
void HexConverter::setStr(const string &str){HexConverter::instr = str; }
int HexConverter::getNum() const {return num;}
void HexConverter::setNum(int num) {HexConverter::num = num; }
const string &HexConverter::getHexstr() const {return hexstr;}
void HexConverter::setHexstr(const string &hexstr) {HexConverter::hexstr = hexstr;}

