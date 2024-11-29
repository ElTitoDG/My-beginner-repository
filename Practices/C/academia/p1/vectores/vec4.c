#include <stdio.h>
#include <stdlib.h>

#define KFILAS 10
#define KCOLUMNAS 10

typedef int TMatriz[KFILAS][KCOLUMNAS];


// rellena la matriz con los valores introducidos por el usuario.
// el primer entero se mete en 0 0 y el ultimo enter en ...
// elemento 0 0:
// elemento 0 1:
// elemento 0 2:
void fillMe(TMatriz me){
    for(int i = 0; i < KFILAS; i++){
        for(int j = 0; j < KCOLUMNAS; j++){
            printf("elemento %d %d: ", i, j);
            scanf("%d", &me[i][j]);
        }
    }
}

// introduce elementos fila 0 (separdos por espacios): 23  2 3 12 2 3 2 31 23 123 123 12 321
// introduce elementos fila 1 (separados por espacios): 2321 3 21 31 23 21  32 4 2 4 2 4 23 442 3 4 234
// ..
void fillMeRow(TMatriz me){
    for(int fila = 0; fila < KFILAS; fila++){
        printf("Introduce los elementos de la fila %d: ", fila);
        for(int columna = 0; columna < KCOLUMNAS; columna++){
            scanf("%d", &me[fila][columna]);
            // cuando relleno una linea y le doy al salto de linea el programa recibe todos elementos introducidos
            // en el buffer y luego el scanf va cogiendo elemento a elemento del buffer.
        }
    }
}

void fillRandom(TMatriz m)
{
	for (int i = 0; i < KFILAS; i++) {
		for (int j = 0; j < KCOLUMNAS; j++) {
			m[i][j] = rand() % 100 + 1;
		}
	}
}

void print(TMatriz m)
{
	for (int i = 0; i < KFILAS; i++) {
		for (int j = 0; j < KCOLUMNAS; j++) {
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
}

void sumaMatriz(TMatriz m1, TMatriz m2, TMatriz suma)
{
	for (int i = 0; i < KFILAS; i++) {
		for (int j = 0; j < KCOLUMNAS; j++) {
			suma[i][j] = m1[i][j] + m2[i][j];
		}
	}
}
// Guarda el menor elemento de toda la matriz y el mayor
void mayorMenor(TMatriz m, int *menor, int *mayor)
{
	//supongo que el primer elemento es el mayor y el menor
	*menor = m[0][0];
	*mayor = m[0][0];

	for (int i = 0; i < KFILAS; i++) {
		for (int j = 0; j < KCOLUMNAS; j++) {
			if (m[i][j] < *menor)
				*menor = m[i][j];
			if (m[i][j] > *mayor)
				*mayor = m[i][j];
		}
	}
}

void fillAll(TMatriz m, int valor)
{

}

void fillZigZag(TMatriz m)
{

}

int main(void)
{
	// matrices
	int m2[3][4] = {{2, 3, 2, 3}, 
			{12, 3, 32, 12},
			{55, 23, 12, 43}};
	

	// Menor fila 0 de m2
	int menor = m2[0][0];
	for (int i = 1; i < 4; i++) {
		if (m2[0][i] < menor)
			menor = m2[0][i];
	}
	// Para todas las filas
	for (int i = 0; i < 3; i++) {
		menor = m2[i][0];
		for (int j = 1; j < 4; j++) {
			if (menor < m2[i][j])
				menor = m2[i][j];
		}
		printf("El menor de la fila %d es %d\n", i, menor);
	}

	int m3[3][5];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			m3[i][j] = rand() % 50 + 1;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%4d", m3[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3; i++) {
		int suma = 0;
		for (int j = 0; j < 5; j++) {
			suma += m3[i][j];
		}
		printf("La suma de la fila %d es: %d\n", i, suma);
	}

	TMatriz m5;
	TMatriz m6;
	TMatriz sumaTotal;


	fillRandom(m5);
	print(m5);
	printf("\n");

	fillRandom(m6);
	print(m6);
	printf("\n");

	sumaMatriz(m5, m6, sumaTotal);
	print(sumaTotal);
	printf("\n");

	

}
