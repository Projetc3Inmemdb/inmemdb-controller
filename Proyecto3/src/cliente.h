/*
 * File:   cliente.h
 * Author: ellioth
 *
 * Created on November 12, 2015, 6:07 PM
 */

#ifndef CLIENTE_H
#define	CLIENTE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include "structs.h"
#include "Constantes.h"


/**
 * clase que hace coneccion contra el servidor
 */
class cliente :public Constantes{
friend class Controler;
public:
	cliente();
	virtual ~cliente();
	void startThread(server_data* datos);
private:
	int _Nserver;
	int _cantHilos;
	conToServer _pTcontn[MaxServers];
	void *conncT(void* datas);
	void sendMSG(void* datas);
	void error(const char* pMsg);
};

#endif	/* CLIENTE_H */
