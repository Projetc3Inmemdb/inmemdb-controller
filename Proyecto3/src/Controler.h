/*
 * File:   Controler.h
 * Author: ellioth
 *
 * Created on November 13, 2015, 5:51 PM
 */

#ifndef CONTROLER_H
#define	CONTROLER_H
#include "Constantes.h"
#include "cliente.h"
#include "structs.h"
#include "serveDatasReader.h"

/**
 * clase que va a funicionar como controlador de los
 * raids y va a almacenar donde se guardaron todos
 * los datos de los servers.
 */
class Controler :public Constantes{
public:
    Controler();
    virtual ~Controler();
    void writeToServer(void* dato);
	void readFromServer(void* dato);
private:
    cliente * _conexiones;
    int _PIRaid;
};

#endif	/* CONTROLER_H */

