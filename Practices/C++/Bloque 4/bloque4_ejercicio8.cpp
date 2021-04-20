/* 8. Escribe un programa que calcule el valor de: 
1+3+5+...+2n-1 */

#include <iostream>
using namespace std;

int main(){
    int suma=0, n;

    cout<<"Introduzca un numero para N: "; cin>>n;

    for(int i=1;i<=2*n-1;i+=2){
        suma += i;
     }
    cout<<"\nEL resultado es: "<<suma<<endl;

    return 0; 
}