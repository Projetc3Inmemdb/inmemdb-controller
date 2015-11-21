/*
 * File:   structs.h
 * Author: ellioth
 *
 * Created on November 12, 2015, 10:23 PM
 */

#ifndef STRUCTS_H
#define	STRUCTS_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/**
 * structs de multiproposito en el proyecto
 * se pueden usar para el cliente para guardar los
 * datos de la conexion.
 **/
struct conToServer{
    int _sockfd;
    int _portno;
    int _n ;
    struct hostent * _server;
    struct sockaddr_in _serv_addr;
};
extern conToServer conett[];

/**
 * struct para almacenar los datos del server.
 * almacena un ip, puerto, numero de thread, mensaje
 * y tamaño de mensaje.
 */
struct server_data{
    char* pIP;
    int pPort;
    int spaceThread;
};
extern server_data thrdDtt;

/**
 * struct para gruar el mensaje que queramos, lo vamos a usar
 * como cuerpo general para enviar mensaje.
 */
struct message{
    void* MSG;
    int sizeMSG;
    int operation;
    int toServer;
};
extern message messDtt;

#endif	/* STRUCTS_H */

