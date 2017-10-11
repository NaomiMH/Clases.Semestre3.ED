/**
 * Naomi Macias Honti a01282098
 * 10 de octubre 2017
 * Tiempo no estimado.
 */
#include <iostream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,a,b,k;
    cin >> n >> m;
    if(n>=3 && m>=1 && n<=pow(double(10),double(7)) && m<=2*pow(double(10),double(5))){
        int arr[n]={0};
        for(int cont=0;cont<m;cont++){
            cin >> a >> b >> k;
            if(b<=n && a>=1 && k>=0 && k<=pow(double(10),double(9))){
                while(a<=b){
                    arr[a-1]=arr[a-1]+k;
                    a++;
                }
            }
        }
        int mayor=arr[0];
        for(int cont=1;cont<n;cont++){
            if(mayor<arr[cont])
                mayor=arr[cont];
        }
        cout << mayor << endl;
    }
    return 0;
}
