#include "xReference.h"
#include "API.h"
#include "../rapidjson/include/rapidjson/stringbuffer.h"
#include "../rapidjson/include/rapidjson/writer.h"

//INTEGER=0,LONG=1,FLOAT=2,SHORT=3,STRING=4,CHAR=5

//void xReference::operator=() {}
/**
 * Overload the operatdor *(reference),
 * @return Retorna el valor al que apunta xReference
 */
void* xReference::operator *() const {
    void* dato;
    StringBuffer jsonMsg;
    Writer<StringBuffer> writer(jsonMsg);
    writer.StartObject();
    writer.String("remitente");writer.String("cliente");
    writer.String("funcion");writer.String("desreferencia");
    writer.String("UUID");writer.String(ID.c_str());
    writer.String("token");writer.String((*globalToken).c_str()); //globalToken es un puntero al token que tiene API
    writer.EndObject();
    cliente.writeData(jsonMsg.GetString());
    string respuesta=cliente.read2();
    Document jsonValue;
    jsonValue.ParseInsitu((char*) respuesta.c_str()).;
    string valor=jsonValue["value"].GetString();
    switch (type){
        case xType::INTEGER:{
            dato=new (int);
            int data=stoi(decode(valor));
            *(int*)dato=data;
            break;
        }
        case xType::LONG:{
            dato=new (long);
            long data=stol(decode(valor));
            *(long*)dato=data;
            break;
        }
    }
    return dato;
}
/**
 * Sobrecarga el operador de comparacion ==
 * @param refer Instancia de xReference a comparar
 * @return Retorna True si son iguales y False en caso contrario
 */

bool xReference::operator ==(const xReference& refer) const {
    bool value=!(size== refer.getSize()) && (ID==refer.getID()) && ((int)type==refer.getType());
    return(value); }

/**
 * Sobrecarga el operador de comparacion !=
 * @param refer Instancia de xReference a comparar
 * @return Retorna True si son diferentes y False si son iguales
 */

bool xReference::operator !=(const xReference& refer) const {
    bool value=!(size== refer.getSize()) && (ID==refer.getID()) && ((int)type==refer.getType());
    return(!value);
}


///////////////////GETERS/SETTERS////////////////////////////////
xReference& xReference::operator=(const xReference& dato) {
    cliente.writeData("HELLO");
}
int xReference::getSize() const {return size;}
void xReference::setSize(int size) {xReference::size = size;}
int xReference::getType() const {return (int) type;}
void xReference::setType(xType type) {xReference::type = type; }
const string &xReference::getID() const {return ID;}
void xReference::setID(const string &ID) {xReference::ID = ID;}

//metodo de prueba para asignar un valor dentro del manager
void xReference::setData(void* valor) {

}


