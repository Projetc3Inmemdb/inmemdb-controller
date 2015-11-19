/* 
 * File:   Constantes.cpp
 * Author: ellioth
 * 
 * Created on November 12, 2015, 6:07 PM
 */

#include "Constantes.h"

const char* Constantes::error1="ERROR opening socket";
const char* Constantes::error2="ERROR connecting";
const char* Constantes::error3="ERROR, no such host\n";
const char* Constantes::error4="ERROR writing to socket";
const char* Constantes::error5="ERROR reading from socket";

/**
 * metodo que recibe una linea caracteres y retorna la cantidad 
 * de letras que contiene.
 * @param msg dato tipo char*, este el mensaje que se le quiere calcular 
 * el largo.
 * @return retorna un dato tipo entero que es el largo del mensaje que 
 * se le paso.
 */
int Constantes::getLenght(const char* msg) {
    return strlen(msg);
}