#ifndef STACK_H
#define STACK_H
#include "nodo.h"
#include <fstream>
#include <iostream>

using namespace std;

template <class T>
class Stack
{
    public:
        Stack(){pTope=NULL;}
        ~Stack(){
            while(pTope!=NULL){
                nodo <T> *tem;
                tem=pTope;
                pTope=pTope->sig;
                delete tem;
            }
        }
        void push(T d){
            nodo <T> *tem;
            tem = new nodo <T> (d);
            tem->sig=pTope;
            pTope=tem;
        }
        void pop(){
            if(pTope!=NULL){
                nodo <T> *tem;
                tem=pTope;
                pTope=pTope->sig;
                delete tem;
            }
        }
        T tope(){
            return pTope->dato;
        }
        bool isEmpty(){
            if(pTope==NULL){
                return true;
            }
            return false;
        }
    private:
        nodo <T> *pTope;
};

#endif // STACK_H
