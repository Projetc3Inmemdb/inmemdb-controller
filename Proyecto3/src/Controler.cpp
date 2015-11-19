/* 
 * File:   Controler.cpp
 * Author: ellioth
 * 
 * Created on November 13, 2015, 5:51 PM
 */

#include "Controler.h"

/**
 * contructor de la clase, inicializa los
 * datos de la clase cliente.
 */
Controler::Controler() {
	this->_conexiones= new cliente();
	/*
	 * falta hacer que el arranque la conexion con todos los server.
	 */
}

/**
 * destructor de la clase.
 */
Controler::~Controler() {
	_conexiones->~cliente();
}

/**
 * metodo que llama al metodo del cliente de
 * enviar al server y se queda esperando que
 * le llegue el mensaje pedido.
 */
void Controler::readFromServer(void* dato){

}

/**
 * metodo que llama al metodo del cliente de
 * enviar al server para escribir un dato en
 * este mismo.
 */
void Controler::writeToServer(void* dato){

}
