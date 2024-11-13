#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Generar un numero de rango [min, max]
int generarAleatorio(int a, int b) { return rand() % (b - a + 1) + a; }

bool esPrimo(int n)
{
	bool es;
	int cd;

	cd = 0;
	for (int d = 1; d <= n; d++) {
		if (n % d == 0)
			cd++;
		if (cd == 2)
			es = true;
		else
			es = false;
	}
	return es;
}

void antsig(int n, int *ant, int *sig)
{
	*ant = n - 1;
	while (!esPrimo(*ant)) { // Mientras que la funcion devuelva false sigo decrementando porque no es primo
		(*ant)--;
	}

	*sig = n + 1;
	while (!esPrimo(*sig)) {
		(*sig)++;
	}
}

int sumarDigitos(int n) 
{
	int suma = 0, digito;

	while (n > 0)
	{
		digito = n % 10;
		suma += digito;
		n /= 10;
	}

	return suma;
}

bool esHarshad(int n) { return n % sumarDigitos(n) == 0; }

int main()
{
	srand(time(NULL));
	int anterior, siguiente;

	antsig(15, &anterior, &siguiente);
	printf("%d %d\n", anterior, siguiente);

	return 0;
}
