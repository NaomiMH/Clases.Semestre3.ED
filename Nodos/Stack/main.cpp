/**
 * Naomi Macias Honti a01282098
 * 19 de Septiembre 2017
 * 1 hr.
 * Lee un archivo donde contiene una serie de corchetes '({[]})', si se encuentran en un orden correcto muestra en pantalla un SI, sino, muestra un NO.
 */
#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

int main()
{
    ifstream arch;
    arch.open("pilas.txt");
    int num;
    arch>>num;
    int cont=0;
    string linea;
    getline(arch,linea);
    while(cont<num){
        Stack <char> lista;
        char dato;
        int cont2=0;
        getline(arch,linea);
        cout << "linea " <<linea << endl;
        dato=linea[cont2];
        cont2++;
        lista.push(dato);
        bool seguir=true;
        while(!lista.isEmpty() && seguir){
            dato=linea[cont2];
            cont2++;
            switch(dato)
            {
            case '{':
            case '[':
            case '(':
                lista.push(dato);
                break;
            case '}':
                dato=lista.tope();
                if(dato!='{')
                    seguir=false;
                else
                    lista.pop();
                break;
            case ']':
                dato=lista.tope();
                if(dato!='[')
                    seguir=false;
                else
                    lista.pop();
                break;
            case ')':
                dato=lista.tope();
                if(dato!='(')
                    seguir=false;
                else
                    lista.pop();
                break;
            }
        }
        if(!seguir)
            cout << "NO" << endl;
        else
            cout << "Si" << endl;
        cont++;
    }
    return 0;
}
