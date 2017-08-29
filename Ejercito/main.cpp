/**
 * Naomi Macias Honti a01282098
 * 28 de Agosto 2017
 * 1 hr 30 min.
 * Inicializa cinco tribus con 0 guerreros, permite agregar, borrar y calcular el promedio de las tribus, finalmente muestra la mejor y peor tribu.
 */
#include <iostream>
#include <vector>

using namespace std;

void agre(vector <int> &vec)
{
    int num;
    cout << "Calidad del guerrero: ";
    cin >> num;
    if(num<0 && num>100){
        cout << "El numero tiene que ser mayor a 0 y menor a 100. Intente de nuevo." << endl;
    }
    else{
        vec.push_back(num);
    }
}

void borr(vector <int> &vec)
{
    cout << "Se borro el ultimo guerrero" << endl;
    vec.pop_back();
}

void prom(vector <int> vec, vector <double> &vecProm)
{
    vector <int>::iterator cont;
    double prom=0;
    int cont1=0;
    for(cont=vec.begin()+1;cont!=vec.end();cont++){
        cont1++;
        prom=prom+*cont;
    }
    prom=prom*1.0/cont1;
    vecProm.at(vec.at(0))=prom;
    cout << "Promedio: " << prom << endl;
}

void most(vector <int> vec)
{
    vector <int>::iterator cont;
    cont=vec.begin();
    cout << "\n\tTribu #" << *cont << endl;
    cout << "Guerreros: " << endl;
    cont++;
    int cont1=1;
    while(cont!=vec.end()){
        cout << cont1 << ". " << *cont << endl;
        cont1++;
        cont++;
    }
}

void mostMejPeo(vector <int> vec1, vector <int> vec2, vector <int> vec3, vector <int> vec4, vector <int> vec0, vector <double> &vecProm)
{
    prom(vec1,vecProm);
    prom(vec2,vecProm);
    prom(vec3,vecProm);
    prom(vec4,vecProm);
    prom(vec0,vecProm);
    vector <double>::iterator maxi;
    vector <double>::iterator mini;
    maxi=vecProm.begin();
    mini=vecProm.begin();
    int maxi1=0, mini1=0;
    for(int cont=0;cont<5;cont++){
        if(vecProm.at(cont)>*maxi){
            maxi=vecProm.begin()+cont;
            maxi1=cont;
        }
        if(vecProm.at(cont)<*mini){
            mini=vecProm.begin()+cont;
            mini1=cont;
        }
    }
    cout << "Tribu mas fuerte es tribu #" << maxi1 << " con promedio de " << *maxi << endl;
    cout << "Tribu mas debil es tribu #" << mini1 << " con promedio de " << *mini << endl;
}

void menu()
{
    cout << "Coloque el numero de la accion a realizar." << endl;
    cout << "1. Agregar un guerrero." << endl;
    cout << "2. Borrar un guerrero." << endl;
    cout << "3. Calcular promedio de una tribu." << endl;
    cout << "4. Mostrar la mejor y peor tribu." << endl;
    cout << "0. Salir." << endl;
}

int main()
{
    vector <int> vec1(1,1);
    vector <int> vec2(1,2);
    vector <int> vec3(1,3);
    vector <int> vec4(1,4);
    vector <int> vec0(1,5);
    vector <double> vecProm(6,0);

    int resp,num;
    do{
        cout << endl;
        menu();
        cout << endl;
        cin >> resp;

        if(resp!=0){
            switch (resp){
            case 1:
                cout << "Tribu #";
                cin >> num;
                if(num==vec1.at(0))
                    agre(vec1);
                else if(num==vec2.at(0))
                    agre(vec2);
                else if(num==vec3.at(0))
                    agre(vec3);
                else if(num==vec4.at(0))
                    agre(vec4);
                else if(num==vec0.at(0))
                    agre(vec0);
                else
                    cout << "Numero invalido, intente de nuevo." << endl;
                break;
            case 2:
                cout << "Tribu #";
                cin >> num;
                if(num==vec1.at(0))
                    borr(vec1);
                else if(num==vec2.at(0))
                    borr(vec2);
                else if(num==vec3.at(0))
                    borr(vec3);
                else if(num==vec4.at(0))
                    borr(vec4);
                else if(num==vec0.at(0))
                    borr(vec0);
                else
                    cout << "Numero invalido, intente de nuevo." << endl;
                break;
            case 3:
                cout << "Tribu #";
                cin >> num;
                if(num==vec1.at(0))
                    prom(vec1,vecProm);
                else if(num==vec2.at(0))
                    prom(vec2,vecProm);
                else if(num==vec3.at(0))
                    prom(vec3,vecProm);
                else if(num==vec4.at(0))
                    prom(vec4,vecProm);
                else if(num==vec0.at(0))
                    prom(vec0,vecProm);
                else
                    cout << "Numero invalido, intente de nuevo." << endl;
                break;
            case 4:
                cout << "\n\tTodo" << endl;
                most(vec1);
                most(vec2);
                most(vec3);
                most(vec4);
                most(vec0);
                cout << "\n\tMejor y peor" << endl;
                mostMejPeo(vec1,vec2,vec3,vec4,vec0,vecProm);
                break;
            }
        }
    }while(resp!=0);
    return 0;
}
