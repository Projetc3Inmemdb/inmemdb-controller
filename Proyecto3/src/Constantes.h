/* 
 * File:   Constantes.h
 * Author: ellioth
 *
 * Created on November 12, 2015, 6:07 PM
 */

#ifndef CONSTANTES_H
#define	CONSTANTES_H

#include <string.h>


class Constantes {
public:
    /**
     * MaxServers=2;
     * es la cantidad de servidores a la que nos vamos a conectar.
     */
    static const int MaxServers=2;
    /**
     * bandera de debug
     */
    static const bool _debug=true;
    /**
     * cero=0
     */
    static const int cero=0;
    /**
     * uno=1
     */
    static const int uno=1;
    /**
     * dos=2
     */
    static const int dos=2;
    /**
     * tres=3
     */
    static const int tres=3;
    /**
     * cuatro=4
     */
    static const int cuatro=4;
    /**
     * cinco=5
     */
    static const int cinco=5;
    /**
     * diez=10
     */
    static const int diez=10;
    /**
     * ipLenght=16
     */
    static const int ipLeght=16;
    /**
	 * ipLenght=16
	 */
	static const int portLeght=4;
    /**
     * DosCincoSeis=256
     */
    static const int DosCientaSeis=256;
    /**
     * QuinDoce=512
     */
    static const int QuinDoce=512;
    /**
     * "ERROR opening socket"
     */
    static const char* error1;
    /**
     * "ERROR connecting"
     */
    static const char* error2;
    /**
     * "ERROR, no such host"
     */
    static const char* error3;
    /**
     * "ERROR writing to socket"
     */
    static const char* error4;
    /**
     * "ERROR reading from socket"
     */
    static const char* error5;

    static const char* direTTServerDatas;
    int getLenght(const char* msg);
};

#endif	/* CONSTANTES_H */

