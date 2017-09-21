#ifndef LISTAS_H
#define LISTAS_H

#include <iostream>
#include "nodo.h"

using namespace std;

template <class T>
class lista
{
    public:
        lista(){inicio=NULL;}
        lista(lista <T> &lis){
            if(lis.inicio!=NULL){
                nodo <T> *tem= lis.inicio;
                nodo <T> *tem2;
                nodo <T> *tem3;
                inicio=new nodo <T> (tem->dato);
                tem=tem->sig;
                tem2=inicio;
                while(tem!=NULL){
                    tem3= new nodo <T> (tem->dato);
                    tem2->sig=tem3;
                    tem2=tem2->sig;
                    tem=tem->sig;
                }
            }
            else
                inicio=NULL;
        }
        ~lista(){
            while(inicio!=NULL){
                nodo <T> *tem;
                tem=inicio;
                inicio=inicio->sig;
                delete tem;
            }
        }
        void muestra(){
            if(inicio!=NULL){
                nodo <T> *tem;
                tem=inicio;
                cout << endl;
                while(tem!=NULL){
                    cout << tem->dato << " ";
                    tem=tem->sig;
                }
                cout << endl << endl;
            }
        }
        int regresTam(){
            int cont=0;
            if(inicio!=NULL){
                nodo <T> *tem;
                tem=inicio;
                cont=1;
                while(tem->sig!=NULL){
                    tem=tem->sig;
                    cont++;
                }
            }
            return cont;
        }
        void agreIni(T dato){
            nodo <T> *tem;
            tem = new nodo <T> (dato);
            tem->sig=inicio;
            inicio=tem;
        }
        void agreFin(T dato){
            nodo <T> *tem = new nodo <T> (dato);
            if(inicio!=NULL){
                nodo <T> *tem2;
                tem2=inicio;
                while(tem2->sig!=NULL){
                    tem2=tem2->sig;
                }
                tem2->sig=tem;
            }
            else
                inicio=tem;

        }
        void borrIni(){
            if(inicio!=NULL){
                nodo <T> *tem;
                tem=inicio;
                inicio=inicio->sig;
                delete tem;
            }
        }
        void borrFin(){
            if(inicio!=NULL){
                nodo <T> *tem;
                tem=inicio;
                while(tem->sig->sig!=NULL){
                    tem=tem->sig;
                }
                delete tem->sig;
                tem->sig=NULL;
            }
        }
        void reversa(){
            if(inicio!=NULL && inicio->sig!=NULL){
                nodo <T> *prev;
                nodo <T> *post;
                post=inicio->sig;
                prev=NULL;
                while(post!=NULL){
                    inicio->sig=prev;
                    prev=inicio;
                    inicio=post;
                    post=inicio->sig;
                }
                inicio->sig=prev;
            }
        }
        void correr(int num){
            if(inicio!=NULL && inicio->sig!=NULL){
                num=num*(-1);
                if(num>0){
                    int cont=0;
                    nodo <T> *tem;
                    tem=inicio;
                    while(tem->sig!=NULL){
                        tem=tem->sig;
                    }
                    tem->sig=inicio;
                    while(cont<num){
                        inicio=inicio->sig;
                        tem=tem->sig;
                        cont++;
                    }
                    tem->sig=NULL;
                }
                else{
                    int cont=0;
                    num=regresTam()+num;
                    nodo <T> *tem;
                    tem=inicio;
                    while(tem->sig!=NULL){
                        tem=tem->sig;
                    }
                    tem->sig=inicio;
                    while(cont<num){
                        inicio=inicio->sig;
                        tem=tem->sig;
                        cont++;
                    }
                    tem->sig=NULL;
                }
            }

        }
        void borrar(int cant, int pos){
            if(inicio!=NULL){
                nodo <T> *tem;
                nodo <T> *tem2;
                tem=inicio;
                int cont=0;
                while(cont<pos-1){
                    if(tem->sig!=NULL){
                        tem=tem->sig;
                        cont++;
                    }
                    else
                        cout << "Error en posicion, el arreglo puede resultar diferente a lo esperado." << endl;
                }
                tem2=tem->sig;
                cont=0;
                while(cont<cant){
                    tem->sig=tem2->sig;
                    if(tem2->sig!=NULL){
                        delete tem2;
                        tem2=tem->sig;
                        cont++;
                    }
                    else{
                        delete tem2;
                        cont=cant;
                    }
                }
            }
        }
        friend bool operator == (lista <T> &lis1, lista <T> &lis2){
            nodo <T> *tem1;
            nodo <T> *tem2;
            tem1=lis1.inicio;
            tem2=lis2.inicio;
            if(lis1.inicio!=NULL){
                if(tem1->dato==tem2->dato){
                    while(tem1!=NULL && tem2!=NULL){
                        if(tem1->dato!=tem2->dato)
                            return false;
                        tem1=tem1->sig;
                        tem2=tem2->sig;
                    }
                    return true;
                }
            }
            else if(lis2.inicio==NULL)
                return true;
            return false;
        }
        friend lista& operator += (lista <T> &lis1, const lista <T> &lis2){
            nodo <T> *tem1=lis1.inicio;
            nodo <T> *tem2=lis2.inicio;
            nodo <T> *tem3;
            if(tem2!=NULL){
                if(tem1==NULL){
                    lis1.inicio= new nodo <T> (tem2->dato);
                    tem1=tem1->sig;
                    tem2=tem2->sig;
                }
                else{
                    while(tem1->sig!=NULL){
                        tem1=tem1->sig;
                    }
                }
                while(tem2!=NULL){
                    tem3=new nodo <T> (tem2->dato);
                    tem1->sig=tem3;
                    tem2=tem2->sig;
                    tem1=tem1->sig;
                }
            }
            return lis1;
        }

    private:
        nodo <T> *inicio;
};

#endif // LISTAS_H
