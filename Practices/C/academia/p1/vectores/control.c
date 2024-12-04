#include <stdio.h>
#include <stdlib.h>

void buscar(int v1[], int buscado, int out[], int SIZE)
{
	for (int i = 0; i < SIZE; i++) {
		if (v1[i] == buscado)
			out[i] = i;
	}
}

int main(void)
{
	int v1[100], res[100];
	for (int i = 0; i < 100; i++) {
		res[i] = -1; v1[i] = 0;
	}

	int searchSize;
	printf("Cuantos numeros quieres meter: ");
	scanf("%d", &searchSize);
	printf("Entroduce los numero: \n");
	for (int i = 0; i < searchSize; i++) {
		scanf("%d", &v1[i]);
	}

	int numBuscado;
	printf("Numero a buscar: ");
	scanf("%d", &numBuscado);

	buscar(v1, numBuscado, res, searchSize);


	printf("[");
	for (int i = 0; i < 50; i++) {
		printf("%d", res[i]);
		if (i != 49)
			printf(", ");
	}
	printf("]\n");

	return 0;
}
