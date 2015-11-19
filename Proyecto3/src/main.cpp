/* 
 * File:   main.cpp
 * Author: ellioth
 *
 * Created on November 12, 2015, 6:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <omp.h>
#include "cliente.h"
using namespace std;

void* print_message(void*){
    cout << "Threading\n"<<"";
    pthread_exit(NULL);
}
/*
 * 
 */
int main(int argc, char** argv) {
    //cliente * nuevo = new cliente();
    ///nuevo->startThread("127.0.0.1",5005);
    pthread_t t1[1];
    int create;
    create=pthread_create(&t1[0], NULL, print_message, NULL);
    if(create){
        cout<<"Error:unable to create thread," <<create<<endl;
        exit(-1);
    }
    cout << "Hello"<<"";
    pthread_exit(NULL);
    return 0;
}

