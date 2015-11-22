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
	serveDatasReader* getServerDatas= new serveDatasReader();
	server_data* AllocServerDatas=(server_data*)getServerDatas->getDatas();
	for(int i=0; i<MaxServers; i++){
		_conexiones->startThread(&AllocServerDatas[i]);
	}
	_PIRaid=0;
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
	_conexiones->sendMSG(dato);
}

/**
 * metodo que llama al metodo del cliente de
 * enviar al server para escribir un dato en
 * este mismo.
 */
void Controler::writeToServer(void* dato){
	if(raid==cero){
		(*(message*)dato).operation=writeF;
		(*(message*)dato).toServer=_PIRaid%MaxServers;
		_conexiones->sendMSG(dato);
		_PIRaid++;
	}
	else if(raid==uno){
		(*(message*)dato).operation=writeF;
		for(int i =0; i<MaxServers; i++){
			(*(message*)dato).toServer=i;
			_conexiones->sendMSG(dato);
		}
	}
	else if(raid==cinco){
		//no se que hacer
	}
	else{
		(*(message*)dato).operation=writeF;
		(*(message*)dato).toServer=cero;
		_conexiones->sendMSG(dato);
	}
}
