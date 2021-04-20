/* Determina si el numero 
es impar o par */
#include <iostream>
using namespace std;

int main(){
    int numero;

    cout<<"Escribe un numero: "; cin>>numero;

    if(numero==0){
        cout<<"\nEL numero es cero"<<endl;
    }else if(numero%2==0) /*<-- Divide el numero entre 2
    y si el resto es iguel a cero el numero es par, 
    sino es impar */ {
        cout<<"\nEL numero es par"<<endl;
    }else{
        cout<<"\nEl numero es impar"<<endl;
    }
    return 0;
}