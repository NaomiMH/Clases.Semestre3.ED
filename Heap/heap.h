#ifndef HEAP_H
#define HEAP_H
///Arbol heap implementado como arreglo
#include <iostream>
using namespace std;

class heap
{
    public:
        heap(int capacidad){
            this->capacidad = capacidad;
            arr=new int[capacidad];
            heapTam=0;
        }

        ///método que regresa el padre de un nodo
        int padre(int num){
            return num/2;
        }

        ///método para regresar el hijo izquierdo de un nodo
        int hijoIzq(int num){
            return num*2;
        }

        ///método para regresar el hijo derecho de un nodo
        int hijoDer(int num){
            return num*2+1;
        }

        ///Método para insertar un valor
        void insertar(int num){
            if(heapTam!=capacidad-1){
                heapTam++;
                arr[heapTam]=num;
                
                int comp=padre(heapTam);
                int cont=heapTam;
                int tem;
                
                while(comp>0 && arr[comp]<num){
                    tem=arr[comp];
                    arr[comp]=num;
                    arr[cont]=tem;
                    cont=comp;
                    comp=padre(comp);
                }
            }
            else
                cout << "Capacidad al limite" << endl;
        }

        ///Método para imprimir el Heap
        void mostrar(){
            for(int cont=1;cont<=heapTam;cont++){
                cout << arr[cont] << " ";
            }
            cout << endl;
        }

    private:
        int capacidad; //capacidad máximo del heap
        int *arr; //pointer a un arreglo de enteros donde
        int heapTam; // va tomando el tamaño actual del heap
};
