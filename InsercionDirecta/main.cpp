/**
 * Naomi Macias Honti a01282098
 * 17 de Agosto 2017
 * Tiempo no estimado.
 * Acomoda un arreglo de datos recibidos con el metodo de ordenamiento de insercion directa.
 */
 #include <iostream>

using namespace std;

int main()
{
    int num, temp, cant,cont;
    cin >> cant;
    int arr[cant]={0};
    for(int cont1=0;cont1<cant;cont1++){
        cin>>num;
        if(num<0){
            cout << "Error, los valores negativos se pasaran a positivos." << endl;
            num=num*(-1);
        }
        arr[cont1]=num;
    }

    for(int cont2=cant/2; cont2<cant; cont2++){
        temp=arr[cont2];
        cont=cont2;
        for(int cont1=cont2-1;cont1>-1 && arr[cont1]>temp;cont1--){
            arr[cont]=arr[cont1];
            arr[cont1]=temp;
            cont--;
        }
    }

    for(int cont1=0;cont1<cant;cont1++){
        cout << arr[cont1] << " . ";
    }
    cout << endl;
    return 0;
}
