#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define KFIL 4
#define KCOL 5

typedef int TMatriz[KFIL][KCOL];

int contarNoNulos(TMatriz m)
{
	int contar = 0;

	for (int i = 0; i < KCOL; i++) {
		for (int j = 0; j < KFIL; j++) {
			if (m[i][j] != 0)
				contar++;
		}
	}
	return contar;
}

bool esReducida(TMatriz m)
{
	int noCeros;
	bool es;

	noCeros = contarNoNulos(m);
	if (noCeros * 3 < KFIL * KCOL)
		es = true;
	else
		es = false;
	return es;
}

int reducirMatriz(TMatriz m, int reducida[])
{
	int cuantos = 0, k = 0;
	for (int i = 0; i < KCOL; i++) {
		for (int j = 0; j < KFIL; j++) {
			if (m[i][j] != 0) {
				reducida[k] = i;
				reducida[k + 1] = j;
				reducida[k + 2] = m[i][j];
				k += 3;
				cuantos++;
			} 
		}
	}
	return cuantos;
}

void leerMatriz(TMatriz m)
{
	for (int i = 0; i < KCOL; i++) {
		printf("Introduce datos por columna %d", i);
		for (int j = 0; j < KFIL; j++) {
			scanf("%d", &m[j][i]);
		}
	}
}

int buscarPosiciones(int v[], int nv, int buscado, int pos[])
{
	int cuantos = 0;

	for (int i = 0; i < nv; i++) {
		if (v[i] == buscado) {
			pos[cuantos] = i;
			cuantos++;
		}
	}

	if (cuantos == 0) {
		for (int i = 0; i < nv; i++) {
			pos[i] = -1;
		}
		cuantos = -1;
	}

	return cuantos;
}

int main()
{
	int v[100], nv;

	do {
		printf("Cuantos elementos: ");
		scanf("%d", &nv);
	} while (nv < 0 || nv > 100);

	for (int i = 0; i < nv; i++) {
		printf("Introduce un elemento: ");
		scanf("%d", &v[i]);
	}

	return 0;
}
