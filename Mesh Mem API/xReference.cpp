//
// Created by jeanpolalvarado on 04/09/16.
//

#include "xReference.h"
#include "API.h"
#include "../rapidjson/include/rapidjson/stringbuffer.h"
#include "../rapidjson/include/rapidjson/writer.h"

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
    writer.EndObject();
    cliente.writeData(jsonMsg.GetString());
    string valor=cliente.readData();
    switch (type){
        case xType::INTEGER:{
            // valor recibido del manager
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


