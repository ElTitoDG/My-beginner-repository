#include <stdio.h>
#include <stdlib.h>

void mostrarTablero(int pj1, int pj2)
{
	printf("Tablero: \n");
	printf("Jugador 1: ");
	
	for (int i = 1; i <= pj1; i++)
	{
		printf("X");
	}
	printf("(%d)\n", pj1);

	for (int i = 1; i <= pj2; i++)
	{
		printf("X");
	}
	printf("(%d)\n", pj2);
}

int lazar_dado() { return 1 + rand() % 6; }

int efecto_casilla(int casilla)
{
	int res;
	if (casilla == 5 || casilla == 10 || casilla == 23)
	{
		res = 3;
	} else if (casilla == 4 || casilla == 15 || casilla == 39)
	{
		res = -3;
	}
}

int main()
{
	int pj1, pj2;



	return 0;
}
