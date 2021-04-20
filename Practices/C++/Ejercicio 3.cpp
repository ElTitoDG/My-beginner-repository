/* Realice un programa que lea de la entrada estandar los siguientes datos de
una persona:

    Edad: dato de tipo entero
    Sexo: dato de tipo caracter
    Altura en metros: dato de tipo Realice

Tras leer los datos, el programa debe mostrarlos en la salida estandar. */

#include <iostream>
using namespace std;

int main(){
    int edad;
    char sexo[10];
    float altura;

    cout<<"Cuantos años tienes: "; cin>>edad;
    cout<<"¿Eres hombre o mujer? "; cin>>sexo;
    cout<<"Cuanto mides en metros: "; cin>>altura;

    cout<<"\nEdad: "<<edad<<endl;
    cout<<"Sexo: "<<sexo<<endl;
    cout<<"Altura: "<<altura<<endl;

  return 0;
}
