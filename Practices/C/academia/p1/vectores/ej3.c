#include <stdio.h>
#include <stdlib.h>

void rellenarHasta(int v[], int size)
{

}

void rellenarTodos(int v[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("Introduce un numero en la posicion %d: ", i);
		scanf("%d", &v[i]);
	}
}

void rellenarRandom(int v[], int size)
{
	int i; 
	for (int i = 0; i < size; i++) {
		v[i] = rand() % 50 + 1;
	}
}

void minYmax(int v[], int size, int *min, int *max)
{
	// Supon que el mayor y el menor son el primero
	*min = v[0];
	*max = v[0];

	// Recorre el vector hasta que encuentra el elemnto de menor y mayor
	for (int i = 0; i < size; i++) {
		if (v[i] < *min)
			*min = v[i];
		else if (v[i] > *max)
			*max = v[i];
	}


}

int search(int v[], int size, int buscado)
{
	int pos, i = 0;
	
	pos = -1;
	while (i < size && pos == -1) {
		if (v[i] == buscado)
			pos = i;
		else
			i++;
	}

	return pos;
}

void copiar(int v[], int w[], int size)
{
	for (int i = 0; i < size; i++) {
		v[i] = w[i];
	}
}

int copiarPares(int v[], int w[], int size)
{
	int np = 0;

	for (int i = 0; i < size; i++) {
		if (v[i] % 2 == 0) {
			w[np] = v[i];
			np++;
		}
	}
	return np;
}

int main()
{
	int vec1[10];

	// Busqueda secuencial
	int searchNum;
	do {
		printf("Introduce un numero entre 1 y 50: ");
		scanf("%d", &searchNum);
	} while (searchNum >= 1 || searchNum <= 50 );
}
