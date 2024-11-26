#include <stdio.h>

int main()
{
	char cadena[100] = "jose12 ma nu el45";
	int espacios, i, vocales, digitos, consonantes;
	
	
	i = 0;
	espacios = 0;
	while(cadena[i] != '\0') {
		if(cadena[i] == ' ') {
			espacios++;
		}
		i++;
	}
	printf("La cantidad de espcios %d\n", espacios);
	
	
	// cantidad de vocales
	i = 0;
	vocales = 0;
	while(cadena[i] != '\0') {
		if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i'
			|| cadena[i] == 'o' || cadena[i] == 'u') {
			vocales++;
		}
		i++;
	}
	printf("Cantidad de vocales %d\n", vocales);
	
	i  = 0;
	digitos = 0;
	while(cadena[i] != '\0') {
		if(cadena[i] >= '0' && cadena[i] <= '9') {
			digitos++;
		}
		i++;
	}
	
	// a..z A..Z 0..9
	// cantidad de consonantes :) je je
	char cadenita[] = "hola Zoe77 como estas666 adios99";
	
	i = 0;
	consonantes = 0;
	while(cadena[i] != '\0') {
		if(cadena[i] >= 'b' && cadena[i] <= 'z') 
			if(cadena[i] != 'e' && cadena[i] != 'i'  && cadena[i] != 'o' && cadena[i] != 'u')
				consonantes++;
		i++;
	}
	printf("Cantidad de consontes: %d\n", consonantes);
	
	
	return 0;
}

