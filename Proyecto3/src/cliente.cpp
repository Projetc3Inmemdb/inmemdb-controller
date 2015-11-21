/* 
 * File:   cliente.cpp
 * Author: ellioth
 * 
 * Created on November 12, 2015, 6:07 PM
 */

#include "cliente.h"

/**
 * constructor de la clase para inicializar algunos datos.
 */
cliente::cliente() {
    _Nserver=0;
}

/**
 * destructor de la clase, elimina los arreglos utilizados.
 */
cliente::~cliente() {
	delete [] _pTcontn;
	//delete [] _hilos;
}

/**
 * metodo para inicializar el hilo pasandole el puerto y el
 * ip del server.
 * recibe un entero que es el puerto y un char* que es el ip.
 */
void cliente::startThread(char* pIP, int Pport) {
    if(_Nserver==MaxServers){
        std::cout<<"max servers reached"<<std::endl;
        return;
    }
    //crear el struct que va a contener los datos de la conexion
    server_data datos;
    //establecer sus atributos.
    datos.pIP=pIP;
    datos.pPort=Pport;
    datos.spaceThread=_Nserver;
    /*establecer el tamaño de mensaje que enviamos
    datos.size=sizeof(message);
    dato que vamos a enviar, en este caso un struct que gruarda un dato
    message msg;
    msg.MSG=123456789;
    establecer el dato
    datos.MSG=(void*)&msg;
    establecer conexion y enviar dato.
    prueba(datos);
    int respond;
    contenedorThread datapThread;
    datapThread.apuntador= this;
    datapThread.datos=datos;
    respond=pthread_create(&_hilos[_Nserver],NULL,cliente::statContt,this);
    if(respond<cero){
    	 std::cout<<"Error:unable to create thread,"<<respond<< std::endl;
		 exit(-uno);
    }*/
    conncT((void*)&datos);
    _Nserver++;
}

/**
 * metodo para realizar la coneccion contra el servidor pedido.
 * recibe un void* que es el struct de la conexion que vamos a
 * realizar.
 */
void * cliente::conncT(void* datas){
    server_data datos= *(server_data*)datas;
    //
    _pTcontn[datos.spaceThread]._sockfd= socket(AF_INET, SOCK_STREAM, cero);
    //
    if (_pTcontn[datos.spaceThread]._sockfd < cero) 
        error(error1);
    //
    _pTcontn[datos.spaceThread]._server = gethostbyname(datos.pIP);
    //
    if (_pTcontn[datos.spaceThread]._server == NULL) {
        fprintf(stderr,error3);
        exit(cero);
    }
    //
    bzero((char *) &(_pTcontn[datos.spaceThread]._serv_addr),
    sizeof(_pTcontn[datos.spaceThread]._serv_addr));
    //
    (_pTcontn[datos.spaceThread]._serv_addr).sin_family = AF_INET;
    //
    bcopy((char *)_pTcontn[datos.spaceThread]._server->h_addr,
    (char *)&_pTcontn[datos.spaceThread]._serv_addr.sin_addr.s_addr,
    _pTcontn[datos.spaceThread]._server->h_length);
    //
    _pTcontn[datos.spaceThread]._serv_addr.sin_port = htons(datos.pPort);
    //
    if (connect(_pTcontn[datos.spaceThread]._sockfd, 
    (struct sockaddr *) &_pTcontn[datos.spaceThread]._serv_addr,
    sizeof(_pTcontn[datos.spaceThread]._serv_addr)) < cero) 
        error(error2);
    return NULL;
}

/**
 * metodo para enviar un mensaje al servidor que queramos, segun
 * y este ya inicializada la conexion contra este.
 * recibe un void* que es el struct que vamos a enviar por
 * medio de TCP hacia el server(este ya tiene que tener especificado
 * todos los datos que requiere el struct message).
 */
void cliente::sendMSG(void* pMsg) {
    message mensaje= *((message*)pMsg);
    int _n;
    _n = write(_pTcontn[mensaje.toServer]._sockfd, mensaje.MSG, sizeof(message));
    if (_n < cero){
        if(_debug)
            std::cout<<"mensaje fallido"<<std::endl;
        error(error4);
    }
    if(_debug)
        std::cout<<"mensaje enviado"<<std::endl;
    bzero(mensaje.MSG, sizeof(message));
}

/*
void cliente::prueba(server_data datos) {
    //establecer el sockfd
    _pTcontn[datos.spaceThread]._sockfd= socket(AF_INET, SOCK_STREAM, cero);
    //revisar si se pudo establecer
    if (_pTcontn[datos.spaceThread]._sockfd < cero) 
        error(error1);
    //inicializar un struct con los datos del sever del ip.
    _pTcontn[datos.spaceThread]._server = gethostbyname(datos.pIP);
    //verificacion de si hay alguien esperando en ese ip.
    if (_pTcontn[datos.spaceThread]._server == NULL) {
        fprintf(stderr,error3);
        exit(cero);
    }
    //limpiar el serv_addr para que no hayan datos que corrompan la direccion
    bzero((char *) &(_pTcontn[datos.spaceThread]._serv_addr),
    sizeof(_pTcontn[datos.spaceThread]._serv_addr));
    //establecer los atributos del serv_addr
    (_pTcontn[datos.spaceThread]._serv_addr).sin_family = AF_INET;
    //establecer los atributos del serv_addr
    bcopy((char *)_pTcontn[datos.spaceThread]._server->h_addr,
    (char *)&_pTcontn[datos.spaceThread]._serv_addr.sin_addr.s_addr,
    _pTcontn[datos.spaceThread]._server->h_length);
    //establecemos el puerto por donde nos vamos a conectar.
    _pTcontn[datos.spaceThread]._serv_addr.sin_port = htons(datos.pPort);
    //revisamos si puede hacer la conecxion contra el servidor.
    if (connect(_pTcontn[datos.spaceThread]._sockfd, 
    (struct sockaddr *) &_pTcontn[datos.spaceThread]._serv_addr,
    sizeof(_pTcontn[datos.spaceThread]._serv_addr)) < cero) 
        error(error2);
    //enviar mensaje al server
    _pTcontn[datos.spaceThread]._n = send(_pTcontn[datos.spaceThread]._sockfd,
            datos.MSG, datos.size,cero);
    //revisar si se pudo enviar el mensaje
    if (_pTcontn[datos.spaceThread]._n < cero) 
         error(error4);
    //limpiar el puntero para recibir nuevas cosas.
    bzero(datos.MSG, sizeof(message));
    //leer se el server nos va a enviar algo
    _pTcontn[datos.spaceThread]._n = read(_pTcontn[datos.spaceThread]._sockfd,
            datos.MSG, datos.size);
    //revisar si lo que envio el server es valido
    if (_pTcontn[datos.spaceThread]._n < cero) 
         error(error5);
    //imprimir lo que se nos envio
    message _dato =*((message*)datos.MSG);
    std::cout<<_dato.MSG<<std::endl;
}*/

/**
 * metodo para imiprimir en consola que hubo un error de conexion
 * contra el servidor.
 * recibe un char*, esta es la especificacion del mensaje que quermos
 * imprimir en pantalla para decir en donde se realizo el fallo.
 */
void cliente::error(const char* pMsg) {
    perror(pMsg);
    exit(uno);
}
