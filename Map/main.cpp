/**
 * Naomi Macias Honti a01282098
 * 17 de noviembre 2017
 * 30 min.
 * Lee un archivo con instrucciones, utiliza la libreria map.
 */
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    // Posibles instrucciones.
    // 1 ( x , y ) = agrega y al estudiante de nombre x
    // 2 ( x ) = elimina la nota del estudiante de nombre x
    // 3 ( x ) = imprime la nota del estudiante de nombre x (si el estudiante no tiene nota, imprime cero)

    ifstream arch;
    arch.open("preguntas.txt");
    map <string,int> mapita;

    int dato, pregunta, calificacion, califante;
    string nombre;
    arch >> dato;

    for (int cont=0;cont<dato;cont++){
        arch >> pregunta;
        arch >> nombre;

        if(pregunta==1){
            arch >> calificacion;
            if(mapita.find(nombre)!=mapita.end())
                califante= mapita.find(nombre)->second;
            else
                califante= 0;
            mapita[nombre]= califante+calificacion;
        }
        else if(pregunta==2)
            mapita.erase(nombre);
        else if(pregunta==3){
            if(mapita.find(nombre)!=mapita.end())
                cout << mapita.find(nombre)->second << endl;
            else
                cout << 0 << endl;
        }
        else
            cout << "instruccion invalida " << endl;
    }
    return 0;
}
