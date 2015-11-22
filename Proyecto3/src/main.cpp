/* 
 * File:   main.cpp
 * Author: ellioth
 *
 * Created on November 12, 2015, 6:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Controler.h"
#include "serveDatasReader.h"
#include "structs.h"
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
	/*ifstream dataReader;
	dataReader.open("/home/ellioth/Desktop/serversDatas.txt");
	char* buffer=(char*)malloc(sizeof(char)*16);
	for(int i =0,j=0; j<2;j++){
		bzero(buffer,16);
		dataReader.seekg(i,dataReader.beg);
		dataReader.read(buffer,15);
		i+=16;
		cout<<buffer<<endl;
		bzero(buffer,16);
		dataReader.seekg(i,dataReader.beg);
		dataReader.read(buffer,4);
		i+=6;
		cout<<buffer<<endl;
	}
	free(buffer);*/
	Controler* conTTServ= new Controler();
	message msg;
	int dato =1234556;
	msg.MSG=(void*)&dato;
	msg.sizeMSG= sizeof(int);
	conTTServ->writeToServer(&msg);
    return 0;
}

