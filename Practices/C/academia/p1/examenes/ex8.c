#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void pedirNumero(int *num)
{
	do {
		printf("Dime un numero entre 2000 y 2500: ");
		scanf("%d", num);
		if (*num < 2000 || *num > 2500)
			printf("El numero %d NO es un dato valido\n", *num);
	} while (*num < 2000 || *num > 2500);
}

bool bisiesto(int num, bool bisiesto)
{
	if ( (num % 4 == 0 && num % 100 != 0) || (num % 400 == 0) ) {
		printf("El año %d tiene 366 dias ", num);
		bisiesto = true;
	} else {
		printf("El año %d tiene 365 dias ", num);
		bisiesto = false;
	}
	return bisiesto;
}

void diaAnoInicio(int num)
{
	// Lunes = 0, Martes = 1; Miercoles = 2; Jueves = 3; Viernes = 4; Sabado = 5; Domingo = 6
	int aux = 5;
	int counter = 2000;

	while (counter < num) {
		if ((counter % 4 == 0 && counter % 100 != 0) || (counter % 400 == 0))
			aux = (aux + 2) % 7;
		else 
			aux = (aux + 1) % 7;
		counter++;
	}	

	switch (aux) {
		case 0:
			printf("y empieza en dia Lunes\n");
			break;
		case 1: 
			printf("y empieza en dia Martes\n");
			break;
		case 2:
			printf("y empieza en dia Miercoles\n");
			break;
		case 3: 
			printf("y empieza en dia Jueves\n");
			break;
		case 4:
			printf("y empieza en dia Viernes\n");
			break;
		case 5: 
			printf("y empieza en dia Sabado\n");
			break;
		case 6:
			printf("y empieza en dia Domingo\n");
			break;
		default: 
			printf("Error\n");
			break;
	}
}

int main()
{
	int numero;
	bool isBisiesto = false;

	pedirNumero(&numero);

	printf("--------------------------------\n");
	bisiesto(numero, isBisiesto);
	diaAnoInicio(numero);
	printf("--------------------------------\n");
	printf("Fin\n");

	return 0;
}
