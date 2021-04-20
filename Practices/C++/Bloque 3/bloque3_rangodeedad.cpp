#include <iostream>
using namespace std;

int main(){
    int edad;

    cout<<"¿Cuantos años tienes? "; cin>>edad;

    if((edad>=18)&&(edad<=25)){
        cout<<"\nBien, tienes los años necesarios "<<endl;
    }else{
        cout<<"\n): No tienes los años necesarios "<<endl;
    }
    return 0;
}