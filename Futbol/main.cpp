/**
 * Naomi Macias Honti a01282098
 * 17 de agosto 2017
 * Tiempo no estimado.
 * Recibe el nombre de un archivo donde lee la cantidad de equipos y partidos jugados, calcula el puntaje y muestra los resultados ordenandolos por puntuaje y por equipo.
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream archE;
    string nombre,dato;
    cin >> nombre;
    nombre=nombre+".txt";
    archE.open(nombre);


    int cantE,cantJ,cont,cant;
    archE>>cantE;
    cantE=cantE;
    archE>>cantJ;
    cantJ=cantJ;
    if((cantJ<1 || cantJ>16) && (cantE<1 || cantE>20))
        cout << "Error."<< endl;


    else if(cantJ){
        cant=cantJ*3;

        string equipos[cantE][cant+1]={{""}};
        cont=0;
        do{
            archE>>equipos[cont][0];
            cont++;
        }while(cont<cantE);


        bool estado=false;
        while(!archE.eof()){
            archE>>dato;
            for(int cont1=0;cont1<cantE;cont1++){
                if(dato==equipos[cont1][0]){
                    int cont2=1;
                    estado=false;
                    do{
                        if(equipos[cont1][cont2]==""){
                            archE>>dato;
                            equipos[cont1][cont2]=dato;
                            archE>>dato;
                            equipos[cont1][cont2+1]=dato;
                            archE>>dato;
                            equipos[cont1][cont2+2]=dato;
                            estado=true;
                        }
                        cont2=cont2+3;
                    }while(!estado);
                }
            }
        }


        int equiposN[cantE][cantJ*2+1]={{9}};
        int num;
        cont=0;
        for(int cont1=0;cont1<cantE;cont1++){
            equiposN[cont1][0]=cont;
            for(int cont2=1, cont3=2;cont2<cantJ*2+1;cont2=cont2+2){
                dato=equipos[cont1][cont3];
                num=dato[0]-48;
                equiposN[cont1][cont2]=num;
                dato=equipos[cont1][cont3+1];
                num=dato[0]-48;
                equiposN[cont1][cont2+1]=num;
                cont3=cont3+3;
            }
            cont++;
        }


        int puntos[cantE][3];
        for(int cont1=0;cont1<cantE;cont1++){
            puntos[cont1][0]=cont1+1;
            puntos[cont1][1]=0;
            num=0;
            cont=1;
            for(int cont2=1;cont2<cantJ*2+1;cont2++){
                num=equiposN[cont1][cont2]-equiposN[cont1][cont2+1]+num;
                dato=equipos[cont1][3*cont-2];
                if(equiposN[cont1][cont2]>equiposN[cont1][cont2+1]){
                    puntos[cont1][1]=puntos[cont1][1]+3;
                    if(dato=="V")
                        puntos[cont1][1]=puntos[cont1][1]+1;
                }
                else if(equiposN[cont1][cont2]==equiposN[cont1][cont2+1]){
                    puntos[cont1][1]=puntos[cont1][1]+1;
                }
                cont2++;
                cont++;
            }
            puntos[cont1][2]=num;
        }


        int temp[3];
        for(int cont1=1;cont1<cantE;cont1++){
            cont=cont1;
            for(int cont2=cont1-1; cont2>-1 && puntos[cont][1]<puntos[cont2][1];cont2--){
                temp[0]=puntos[cont2][0];
                temp[1]=puntos[cont2][1];
                temp[2]=puntos[cont2][2];

                puntos[cont2][0]=puntos[cont][0];
                puntos[cont2][1]=puntos[cont][1];
                puntos[cont2][2]=puntos[cont][2];

                puntos[cont][0]=temp[0];
                puntos[cont][1]=temp[1];
                puntos[cont][2]=temp[2];

                cont=cont2;
            }
        }

        cout << endl<< "Ordenado por puntuacion." << endl;
        for(int cont1=cantE-1;cont1>-1;cont1--){
            cout << equipos[puntos[cont1][0]-1][0] << " ";
            cout << puntos[cont1][1] << " ";
            cout << puntos[cont1][2] << endl;
        }
        cout << endl;

        string temp1,temp2;
        temp2=equipos[puntos[0][0]-1][0];
        estado=true;
        while(estado){
            estado=false;
            temp2=equipos[puntos[0][0]-1][0];
            for(int cont1=1;cont1<cantE;cont1++){
                temp1=temp2;
                temp2=equipos[puntos[cont1][0]-1][0];
                if(temp1[0]-1>temp2[0]-1){
                    temp[0]=puntos[cont1-1][0];
                    temp[1]=puntos[cont1-1][1];
                    temp[2]=puntos[cont1-1][2];

                    puntos[cont1-1][0]=puntos[cont1][0];
                    puntos[cont1-1][1]=puntos[cont1][1];
                    puntos[cont1-1][2]=puntos[cont1][2];

                    puntos[cont1][0]=temp[0];
                    puntos[cont1][1]=temp[1];
                    puntos[cont1][2]=temp[2];

                    temp2=equipos[puntos[cont1][0]-1][0];
                    estado=true;
                }
            }
        }

        cout << endl << "Ordenado por equipo." << endl;

        for(int cont1=0;cont1<cantE;cont1++){
            cout << equipos[puntos[cont1][0]-1][0] << " ";
            cout << puntos[cont1][1] << " ";
            cout << puntos[cont1][2] << endl;
        }
        cout << endl;
    }
    return 0;
}
