/**
 * Naomi Macias Honti a01282098
 * 8 de Septiembre 2017
 * Tiempo no estimado.
 * Crea una lista de nodos, realiza varias funciones, con sobrecarga de operadores == y +=, y muestra las diferentes funciones disponibles.
 */
#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    lista <int> lis;
    cout << "\tMuestra" << endl;
    lis.muestra();
    cout << "\tAgrega al final -1" << endl;
    lis.agreFin(-1);
    lis.muestra();
    cout << "\tAgrega inicio 0" << endl;
    lis.agreIni(0);
    lis.muestra();
    cout << "\tRegresa tamano 2: " << lis.regresTam() << endl << endl;
    cout << "\tReversa -1 0" << endl;
    lis.reversa();
    lis.muestra();
    cout << "\tAgrega final 1 2 3 4 5 6 7 8 9 10" << endl;
    lis.agreFin(1);
    lis.agreFin(2);
    lis.agreFin(3);
    lis.agreFin(4);
    lis.agreFin(5);
    lis.agreFin(6);
    lis.agreFin(7);
    lis.agreFin(8);
    lis.agreFin(9);
    lis.agreFin(10);
    lis.muestra();
    cout << "\tElimina final 10" << endl;
    lis.borrFin();
    lis.muestra();
    cout << "\tElimina inicio -1" << endl;
    lis.borrIni();
    lis.muestra();
    cout << "\tInicializa lis2 con los datos de lis" << endl;
    lista <int> lis2(lis);
    lis.muestra();
    cout << "\tComprueba si las dos listas son iguales" << endl;
    cout << "lis" << endl;
    lis.muestra();
    cout << "lis2" << endl;
    lis2.muestra();
    if(lis==lis2)
        cout << "\nSon iguales." << endl;
    else
        cout << "\nSon diferentes." << endl;
    cout << "\n\tCorrer 2 posiciones" << endl;
    lis.correr(2);
    lis.muestra();
    cout << "\tComprueba si las dos listas son iguales" << endl;
    cout << "lis" << endl;
    lis.muestra();
    cout << "lis2" << endl;
    lis2.muestra();
    if(lis==lis2)
        cout << "\nSon iguales." << endl;
    else
        cout << "\nSon diferentes." << endl;
    cout << "\tCorrer -1 posiciones" << endl;
    lis.correr(-1);
    lis.muestra();
    cout << "\tBorrar 3 numeros a partir del numero en la posicion 2" << endl;
    lis2.borrar(3,2);
    lis2.muestra();
    cout << "\tAgregar lis2 a lis  lis+=lis2" << endl;
    cout << "Antes lis" << endl;
    lis.muestra();
    cout << "Antes lis2" << endl;
    lis2.muestra();
    lis+=lis2;
    cout << "Despues lis" << endl;
    lis.muestra();
    cout << "Despues lis2" << endl;
    lis2.muestra();
    return 0;
}
