#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ejercicios faciles
// Rellena un vector de 20 elementos con los valores desde:
//      -> 1 hasta 20, e imprimelo
//      -> 2, 4, 6, 8, ..., 40 e imprimelo
// DONE

// Rellena un vector de 20 elementos con valores aleatorios entre 1 y 20:
//      muestralo por pantalla
//      pide dos valores a y b (a debe ser menor o igual que b).
//      muestra la cantidad de elementos del vector que estan dentro de ese rango.
// DONE



// Ejercicios dificles.
// - Rellena un vector de 10 elementos con los valores introducidos por el usuario
//      posicion 0: <34>
//      posicion 1: <31>
//      ...
//      posicion 9: <31>

//  - Imprime el vector anterior

// - Rellena un vector de 10 elementos con los 10 primeros valores primos!

// - Rellena un vector de 10 elementos con los valores introducidos por el usuario,
// los valores que no sean pares se ignoraran
//      posicion 0: 2
//      posicion 1: 3
//      posicion 1: 5
//      posicion 1: 12
//      posicion 2: 24
//      ....


int main(void)
{
	srand(time(NULL));

	int vec1[20];
	for (int i = 1; i <= 20; i++)
	{
		vec1[i] = i;
	}
	for (int i = 1; i <= 20; i++)
	{
		printf("%d ", vec1[i]);
	}
	printf("\n");

	int vec2[20];
	for (int i = 0; i < 20; i++)
	{
		vec2[i] = rand() % 21;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");

	int vec3[10];
	for (int i = 0; i < 10; i++)
	{
		printf("posicion %d: ", i);
		scanf("%d", &vec3[i]);
	}

	return 0;
}
