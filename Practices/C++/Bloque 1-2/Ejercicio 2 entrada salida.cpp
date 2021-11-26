/* Escribe un programa que lea de la entrada estandar el precio de un producto
y muestre en la salida estandar el precio del producto al aplicarle el IVA */

#include <iostream>
using namespace std;

int main(){
  float preciobase;
  float preciofinal;
  cout<<"Introduce el precio base del producto: "; cin>>preciobase;

  preciofinal = (preciobase*21/100)+preciobase;

cout<<"\nEl precio final sera de: "<<preciofinal<<endl;

return 0;
}
