#include <stdio.h>

void dibujar(int ancho, int alto)
{
	for (int i = 1; i <= ancho + 2; i++)
	{
		printf(".");
	}
	printf("\n");

	for (int i = 1; i <= alto; i++)
	{
		printf(".");
		for (int j = 1; j <= ancho; j++)
		{
			printf("O");
		}
		printf("\n");
	}

	for (int i = 1; i <= ancho + 2; i++)
	{
		printf(".");
	}
	printf(".\n");
}

int main()
{
	char c;
	int cuantos = 0, codigo = 0;
	printf("Introduczca un pin 4 codigos. Finaliza con un .");
	do {
		c = getchar();
		if (c != '.') {
			cuantos++;
			codigo = codigo * 10 + (c - '0'); // pasar de ascii a decimal 
		}
	}while (c != '.');
	
	// Vaciar el buffer | Limpiar el buffer
	do {
		c = getchar();
	} while (c != '\n');

	printf("Cuantos: %d\n", cuantos);
	printf("Codigo: %d\n", codigo);



}
