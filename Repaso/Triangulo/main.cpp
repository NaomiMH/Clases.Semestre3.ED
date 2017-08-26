/**
 * Naomi Macias Honti a01282098
 * 17 de agosto 2017
 * Tiempo no estimado.
 * Recibe un tamano para una matriz cuadrada, maximo 5, y los datos para ser llenado, finalmente comprueba si la matriz creada contiene un triangulo superior.
 */
#include <iostream>

using namespace std;

bool veriMatriz(int arr[5][5], int tam)
{
    for(int cont=0; cont<tam; cont++){
        for(int cont2=tam-1; cont2>cont; cont2--){
            if(arr[cont2][cont]!=0)
                return false;
        }
    }
    return true;
}

void mostMatriz(int arr[5][5], int tam)
{
    for(int cont=0; cont<tam; cont++){
        for(int cont2=0; cont2<tam; cont2++){
            cout << arr[cont][cont2];
        }
        cout << endl;
    }
}

int main()
{
    int arr[5][5]={{0}};
    int tam, num;
    do{
        cout << "Tamano: ";
        cin >> tam;
        if(tam>5)
            cout << "El numero tiene que ser menor de 6." << endl;
        else if (tam<2)
            cout << "El numero tiene que ser mayor de 1." << endl;
    }while(tam>5 || tam<2);

    cout << endl;

    for(int cont=0; cont<tam; cont++){
        for(int cont2=0; cont2<tam; cont2++){
            cin>>num;
            arr[cont][cont2]=num;
        }
    }

    mostMatriz(arr,tam);
    if(veriMatriz(arr,tam))
        cout << "Es Triangular superior." << endl;
    else
        cout << "No es Triangular superior." << endl;
    return 0;
}
