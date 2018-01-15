#include <iostream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long int n,m,a,b,k,mayor=0;
    cin >> n >> m;
    long int *arr = new long int [n];
    for(int cont=0;cont<m;cont++){
        cin >> a >> b >> k;
        while(a<=b){
            arr[a-1]=arr[a-1]+k;
            if(mayor<arr[a-1])
                mayor=arr[a-1];
            a++;
        }
    }
    cout << mayor << endl;
    delete[] arr;
    return 0;
}
