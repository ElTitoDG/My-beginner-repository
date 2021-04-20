#include <iostream>
using namespace std;

int main(){
    int suma=0, n;

    cout<<"Introduzca un numero para N: "; cin>>n;


    for(int i=1;i<=n;i++){
        suma += i;
    }
    cout<<"\nLa suma total es: "<<suma<<endl; 
    return 0;
}