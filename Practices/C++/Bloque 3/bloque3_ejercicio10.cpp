/* 10. Mostrar los meses del años, pidiendole al 
usuario un numero entre (1-12), y mostrar 
el mes al que corresponde */

#include <iostream>
using namespace std;

int main(){
    int mes;

    cout<<"Introduce un numero del 1 al 12: "; cin>>mes;

    switch(mes){
        case 1: cout<<"Ese numero corresponde a Enero"; break;
        case 2: cout<<"Ese numero corresponde a Febrero"; break;
        case 3: cout<<"Ese numero corresponde a Marzo"; break;
        case 4: cout<<"Ese numero corresponde a Abril"; break;
        case 5: cout<<"Ese numero corresponde a Mayo"; break;
        case 6: cout<<"Ese numero corresponde a Junio"; break;
        case 7: cout<<"Ese numero corresponde a Julio"; break;
        case 8: cout<<"Ese numero corresponde a Agosto"; break;
        case 9: cout<<"Ese numero corresponde a Septiembre"; break;
        case 10: cout<<"Ese numero corresponde a Octubre"; break;
        case 11: cout<<"Ese numero corresponde a Noviembre"; break;
        case 12: cout<<"Ese numero corresponde a Diciembre"; break;
    }   
    return 0;
}