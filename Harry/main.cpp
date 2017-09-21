/**
 * Naomi Macias Honti a01282098
 * 20 de Septiembre 2017
 * 42 min.
 * Recibe un archivo con instrucciones. La primera linea contiene la cantidad de monedas que tendra Harry, la segunda linea contiene el valor de dichas monedas, la tercera linea contiene el numero de instrucciones que vendran a continuacion y un numero meta. Las instrucciones pueden ser Harry (agregar moneda Harry a Monk) o Eliminar (eliminar moneda Monk). Al final se suma el total del valor de las monedas Monk, en caso de alcanzar la meta, se muestra la cantidad de monedas Monk, en caso contrario se muestra -1.
 */
#include <iostream>
#include "Stack.h"
#include <fstream>

using namespace std;

int main()
{
    Stack <int> Harry;
    Stack <int> Monk;
    string dato;
    cout << "Nombre del archivo (con terminacion): ";
    cin >> dato;
    ifstream arch;
    arch.open(dato);
    int num,cant,cont,meta,suma;
    arch >> cant;
    if(cant<1 || cant>104)
        cout << "Error en valor N";
    else{
        for(cont=0;cont<cant;cont++){
            arch>>num;
            Harry.push(num);
        }
        arch >> cant;
        arch >> meta;
        for(cont=0;cont<cant;cont++){
            arch >> dato;
            switch(dato[0])
            {
            case 'H':
                Monk.push(Harry.tope());
                Harry.pop();
                break;
            case 'E':
                Monk.pop();
                break;
            default:
                cout << "Instruccion invalida." << endl;
                break;
            }
        }
        cont=0;
        for(suma=0;!Monk.isEmpty();Monk.pop()){
            suma=suma+Monk.tope();
            cont++;
        }
        if(suma==meta)
            cout << cont << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}
