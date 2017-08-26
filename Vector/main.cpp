/**
 * Naomi Macias Honti a01282098
 * 25 de Agosto 2017
 * Tiempo no estimado.
 * Uso de la libreria vector para replicar un arreglo en otro, repitiendo el numero n por n cantidad de veces.
 */
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void replica(vector <int> vec, vector <int> &vec2)
{
    vector <int>::iterator cont;
    for(cont=vec.begin();cont!=vec.end();cont++){
        for(int cont2=0; cont2<*cont;cont2++){
            vec2.push_back(*cont);
        }
    }
}

void impresion(vector <int> vec)
{
    vector <int>::iterator cont;
    for(cont=vec.begin();cont!=vec.end();cont++){
        cout << *cont << " ";
    }
    cout << endl;
}

int main()
{
    int num;
    cin >> num;
    vector <int> vec(num,0);
    vector <int> vec2;
    for(int cont=0; cont<num; cont++){
        vec.at(cont)=(rand()%10+1);
        cout << vec.at(cont) << endl;
    }
    replica(vec,vec2);
    impresion(vec);
    impresion(vec2);
    return 0;
}
