/**
 * Naomi Macias Honti a01282098
 * 17 de Agosto 2017
 * Tiempo no estimado.
 * Agarra el primer numero del arreglo y acomoda los demas numeros segun si son menores o mayores al numero, poniendolos en la izquierda o derecha del numero segun el numero.
 */
#include <iostream>

using namespace std;

int main()
{
    int num, cant,temp,temp2;
    cin >> cant;
    int arr[cant]={0};
    for(int cont=0;cont<cant;cont++){
        cin>>num;
        if(num<0){
            cout << "Error, los valores negativos se pasaran a positivos." << endl;
            num=num*(-1);
        }
        arr[cont]=num;
    }

    temp=arr[0];
    arr[0]=arr[cant-1];
    arr[cant-1]=temp;

    for(int cont1=0;cont1<cant && arr[cont1]!=temp;cont1++){
        if(arr[cont1]>temp){
            temp2=arr[cont1];
            for(int cont2=cont1+1;cont2<cant;cont2++)
                arr[cont2-1]=arr[cont2];
            arr[cant-1]=temp2;
            cont1--;
        }
    }

    for(int cont1=0;cont1<cant;cont1++){
        cout << arr[cont1] << " . ";
    }
    cout << endl;
    return 0;
}
