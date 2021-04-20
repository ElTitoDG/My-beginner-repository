/* 2. Escriba un programa que lea tres numeros 
y determine cual de ellos es el mayor */
#include <iostream>
using namespace std;

int main(){
    float n1, n2, n3;

    cout<<"Escribe tres numeros: "; cin>>n1>>n2>>n3;

    if((n1>n2)&&(n1>n3)){
        cout<<"El numero mayor es: "<<n1<<endl;
    }else if((n2>n1)&&(n2>n3)){
        cout<<"EL numero mayor es: "<<n2<<endl;
    }else{
        cout<<"El numero mayor es: "<<n3<<endl;
    }
    return 0;
}