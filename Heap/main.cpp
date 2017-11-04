/**
 * Naomi Macias Honti a01282098
 * 4 de Noviembre 2017
 * 1 hr 30 min.
 * Utiliza un arreglo para ordenar los datos en forma de arbol. El nodo padre debe de mayor o menor, segun el caso, que sus hijos.
 */
#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
    heap lista(9);
    lista.insertar(9);
    lista.insertar(3);
    lista.insertar(6);
    lista.insertar(10);
    lista.insertar(2);
    lista.insertar(8);
    lista.insertar(1);
    lista.insertar(4);
    lista.mostrar();
    return 0;
}
