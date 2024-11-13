#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main()
{
	srand(time(NULL));

	int vec[SIZE];

	for (int i = 0; i < SIZE; i++) {
		vec[i] = rand() % 100;
	}

	printf("[");
	for(int i = 0; i < SIZE; i++) {
		printf("%d", vec[i]);
		if (i != SIZE - 1)
			printf(", ");
	}
	printf("]\n");

	int sumaPar = 0, cantidadImpar = 0;
	for (int i = 0; i < SIZE; i++) {
		if (vec[i] % 2 == 0)
			sumaPar += vec[i];
		else
			cantidadImpar++;
	}

	printf("La suma de pares: %d\nLa cantidad de impares: %d\n", sumaPar, cantidadImpar);

	return 0;
}
