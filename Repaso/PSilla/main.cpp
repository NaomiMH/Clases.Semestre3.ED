/**
 * Naomi Macias Honti a01282098
 * 10 de agosto 2017
 * Tiempo no estimado.
 * Recibe un tamano de columnas, renglones y los numeros para llenar una matriz, despues busca si hay numeros silla, que sean el numero mas grande en su columna pero menor en el renglon o que sean menor en su columna y mayor en su renglon.
 */
#include <iostream>

using namespace std;

bool coluMa(int arr[30][30], int col, int ren, int num, int colNum, int renNum)
{
    for(int cont=0; cont<col; cont++){
        if(num<=arr[cont][renNum] && cont!=colNum){
            return false;
        }
    }
    for(int cont=0; cont<ren; cont++){
        if(num>=arr[colNum][cont] && cont!=renNum){
            return false;
        }
    }
    return true;
}

bool coluMe(int arr[30][30], int col, int ren, int num, int colNum, int renNum)
{
    for(int cont=0; cont<col; cont++){
        if(num>=arr[cont][renNum] && cont!=colNum){
            return false;
        }
    }
    for(int cont=0; cont<ren; cont++){
        if(num<=arr[colNum][cont] && cont!=renNum){
            return false;
        }
    }
    return true;
}

void calcula(int arr[30][30],int col,int ren)
{
    int num;
    cout << endl;
    for(int cont=0; cont<col; cont++){
        for(int cont2=0; cont2<ren; cont2++){
            num=arr[cont][cont2];
            if(coluMa(arr,col,ren,num,cont,cont2)){cout << num << " ";}
            else if(coluMe(arr,col,ren,num,cont,cont2)){cout << num << " ";}
        }
    }

}

void mostMatriz(int arr[30][30], int col, int ren)
{
    cout << endl;
    for(int cont=0; cont<col; cont++){
        for(int cont2=0; cont2<ren; cont2++){
            cout << arr[cont][cont2];
        }
        cout << endl;
    }
}

void llenar(int arr[30][30], int col, int ren)
{
    int num;
    for(int cont=0; cont<col; cont++){
        for(int cont2=0; cont2<ren; cont2++){
            cin>> num;
            arr[cont][cont2]=num;
        }
    }

    calcula(arr,col,ren);
}

int main()
{
    int arr[30][30]={{0}};
    int col,ren;
    cout << "Columnas: ";
    cin >> col;
    if(col>30){
        cout << "Maximo 30, se pondra por default 30." << endl;
        col=30;
    }else if(col<1){
        cout << "Minimo 1, se pondra por default 1." << endl;
        col=1;
    }
    cout << "Renglones: ";
    cin >> ren;
    if(ren>30){
        cout << "Maximo 30, se pondra por default 30." << endl;
        ren=30;
    }else if(ren<1){
        cout << "Minimo 1, se pondra por default 1." << endl;
        ren=1;
    }

    llenar(arr,col,ren);
    return 0;
}
