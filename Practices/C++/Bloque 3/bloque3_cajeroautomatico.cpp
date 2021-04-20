#include <iostream>
using namespace std;

int main(){
    
    
    int saldo_inicial = 1000, opc, contrasena;
    float extra, saldo = 0, retiro;  
    
    cout<<"\nIntroduzca su contraseña: "; cin>>contrasena; 
        if(contrasena == 1234){
    cout<<"\tBienvenido a su cuenta: "<<endl;
    cout<<"\n1. Ingresar dinero en cuenta"<<endl;
    cout<<"\n2. Retirar dinero de la cuenta "<<endl;
    cout<<"\n3. Salida"<<endl; 
    cout<<"\nOpcion: "; cin>>opc;



    switch(opc){
        case 1:
            cout<<"Digite la cantidad a ingresar: "; cin>>extra;
            saldo = saldo_inicial+extra;
            cout<<"\n\tDinero en cuenta: "<<saldo;
            cout<<"\n"<<endl; break; 
        case 2:
            cout<<"\nDigite la cantidad de dinero que va a retirar: "; cin>>retiro;
            if(retiro > saldo_inicial){
                cout<<"\n\tCantidad no disponible";
                cout<<"\n"<<endl;
            }else{
                saldo = saldo_inicial-retiro;
                cout<<"\n\tDinero en cuenta: "<<saldo;
                cout<<"\n"<<endl;
            }
        case 3:
            cout<<"\n\tGracias por usar nuestros servicios";
            cout<<"\n"<<endl; break; 

    }
        }else{
            cout<<"\n\tContraseña incorrecta, intentelo de nuevo"<<endl;
            cout<<"\n"<<endl;
        }
    return 0;
}