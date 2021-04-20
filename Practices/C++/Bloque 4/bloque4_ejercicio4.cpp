/* 4. Escribe un programa que tome cada 4 horas la temperatura exterior, leyendola durante un periodo de 24 horas.
Es decir,  de leer 6 temperaturas. Calcule la temperatura media del día, la temperatura mas alta y la mas baja */

#include <iostream>
using namespace std;

int main(){
    float temperatura, suma_temperatura=0,temperatura_media;
    float temperatura_alta=0,temperatura_baja=999;

    for(int i=0;i<=24;i+=4){
        cout<<"Escribe la temperatura a las "<<i<<": "; cin>>temperatura;
    }

    suma_temperatura+=temperatura;

    if(temperatura>temperatura_alta){
        temperatura_alta=temperatura;
    } if(temperatura<temperatura_baja){
        temperatura_baja=temperatura;
    }

   temperatura_media = suma_temperatura/6;

   cout<<"\nLa temperatura media es: "<<temperatura_media<<endl;
   cout<<"\nLa temperatura mas alta es: "<<temperatura_alta<<endl;
   cout<<"\nLa temperatura mas baja es: "<<temperatura_baja<<endl;
    return 0;
}