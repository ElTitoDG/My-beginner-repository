/* 4. Comprobar si un numero es 
positivo o negativo */

#include <iostream>
using namespace std;

int main(){
    int n1;

    cout<<"Digite dos numeros: "; cin>>n1;

    if(n1==0){
        cout<<"\nEl numero es cero"<<endl;
    }else if(n1>0){
        cout<<"\nEl numero es positivo"<<endl;
    }else{
        cout<<"\nEl numero es negativo"<<endl;
    }
    return 0;
}