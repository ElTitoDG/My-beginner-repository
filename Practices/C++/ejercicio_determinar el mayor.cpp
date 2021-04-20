#include <iostream>
using namespace std;

int main(){
    float n1, n2;

    cout<<"Escribe dos numeros: "; 
    cin>>n1>>n2; //<--Para guardar dos variables en una sola orden 

        if (n1==n2){
            cout<<"Los numeros son iguales";
        }
        else if(n1>n2){
            cout<<"\nEL mayor es: "<<n1<<endl;
        }
        else{
            cout<<"\nEl mayor es: "<<n2<<endl;
        }

    return 0;
}