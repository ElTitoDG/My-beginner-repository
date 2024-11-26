#include <stdio.h>
#include <string.h>

// cadenas de caracteres
int main(){
	// los 3 de abajo son vectores de caracteres
	char vectorChar[10] = {'a', 'b', 'c', 'd', 'f'};

    	// los 2 de abajo son vectores de caracteres que contienen cadenas de caracteres
    	char cadena[10] = {'d', 'f', 'd', '\0'}; // es un vector de caracteres que contiene el caracter \0
    	char cadena3[20] = "hola"; // char cadena3[20] = {'h', 'o', 'l', 'a', '\0'}

    	printf("%s\n", cadena);     // recorre hasta el \0
    	printf("%s\n", cadena3);

    	printf("longitud: %ld\n", strlen(cadena)); // devuelve el numero de caracteres almacenados / posicion de \0
    	printf("longitud: %ld\n", strlen(cadena3));

    	// recorro a mano!!
	printf("Imprimimos caracter a caracter: ");
    	int i = 0;
    	int tam = strlen(cadena);   // // la recorro cada vez...
    	while(i < tam){
        	printf("%c", cadena[i]);
        	i++;
    	}
    	printf("\n");

	// recorro hasta encontrar el caracter nulo 
	// por el que acaban todas las cadenas
	printf("Imprimimos caracter a caracter: ");
    	i = 0;
    	while(cadena[i] != '\0'){
        	printf("%c", cadena[i]);
        	i++;
    	}
    	printf("\n");

    	printf("mete una cadena: ");
    	// %s, %d ignoran los espacios que tengais delante!!!
    	scanf("%s", cadena); // le hasta el espacio, que rompe la secuencia
    	// ese espacio.
    	printf("meteo otra cadena: ");
    	scanf("%s", cadena3);
    	printf("cadena 1: <%s>, cadena 3 <%s>\n", cadena, cadena3);

    	printf("Meteme la cadena: ");
    	scanf("%[^\n]", cadena);
    	printf("<%s>", cadena);


    return 0;
}
