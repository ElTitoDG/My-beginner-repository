
#include<iostream>

using namespace std;

int main(){
	int numero,conteo=0; 
	
	do{
		cout<<"Digite un numero: "; 
		cin>>numero;
		if(numero>0){
			conteo++; //aumentamos el conteo cada vez que encuentra un numero mayor a 0	
		}
	}while(numero != 0);
	
	
	cout<<"\nEl total de numeros mayores que 0 es: "<<conteo;
	
	

	return 0;
}