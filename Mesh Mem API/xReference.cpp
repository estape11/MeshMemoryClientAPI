//
// Created by jeanpolalvarado on 04/09/16.
//

#include "xReference.h"
///*
//void xReference::operator=() {}
//
///*
// * Sobrecarga el operador *(referencia),
// * @return Retorna el valor al que apunta xReference
// */
//int xReference::operator *() const {return (*value);}
///**
// * Sobrecarga el operador de comparacion ==
// * @param refer Instancia de xReference a comparar
// * @return Retorna True si son iguales y False en caso contrario
// */
//
//bool xReference::operator ==(const xReference& refer) const {
//    return((size== refer.getSize()) && (value==refer.getValue())); }
//
///**
// * Sobrecarga el operador de comparacion !=
// * @param refer Instancia de xReference a comparar
// * @return Retorna True si son diferentes y False si son iguales
// */
//bool xReference::operator !=(const xReference& refer) const {
//    return (!((size== refer.getSize()) && (value==refer.getValue()))); }



///////////////////GETERS/SETTERS////////////////////////////////

int xReference::getSize() const {return size;}
void xReference::setSize(int size) {xReference::size = size;}
int xReference::getType() const {return type;}
void xReference::setType(xType type) {xReference::type = type; }
const string &xReference::getID() const {return ID;}
void xReference::setID(const string &ID) {xReference::ID = ID;}


