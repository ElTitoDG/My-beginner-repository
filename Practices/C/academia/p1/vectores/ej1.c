#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Busca  si existe algun divisor que no sea ni 1 ni el numero
//
bool esPrimo(int n)
{
	bool es = false;
	int divisor;

	if (n > 1)
	{
		es = true; // supones que es primo
		divisor = 2;
		while (divisor <= n/2 && es == true)
		{
			if (n % divisor == 0)
				es = false;
			else
				divisor++;
		}
	}
	return es;
}

int main(void)
{
	srand(time(NULL));

	// 1. Rellena un vector de 20 elementos con los valores desde:
	//      -> 1 hasta 20, e imprimelo
	//      -> 2, 4, 6, 8, ..., 40 e imprimelo
	// DONE
	int vec1[20];
	for (int i = 0; i < 20; i++)
	{
		vec1[i] = i + 1;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", vec1[i]);
	}
	printf("\n");

	
	int vec0[20];
	for (int i = 0; i < 20; i++)
	{
		vec0[i] = (i + 1) * 2;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", vec0[i]);
	}
	printf("\n");

	
	// 2. Rellena un vector de 20 elementos con valores aleatorios entre 1 y 20:
	//      muestralo por pantalla
	//      pide dos valores a y b (a debe ser menor o igual que b).
	//      muestra la cantidad de elementos del vector que estan dentro de ese rango.
	// DONE
	int vec2[20];
	for (int i = 0; i < 20; i++)
	{
		vec2[i] = rand() % 20 + 1;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");


	int a, b, cuantos = 0;
	do {
		printf("a: ");
		scanf("%d", &a);
		printf("b: ");
		scanf("%d", &b);
	} while (a > b);
	for (int i = 0; i < 20; i++)
	{
		if (vec2[i] >= a && vec2[i] <= b)
		{
			cuantos++;
		}
	}
	printf("Has encontrado %d en el rango de [%d %d]\n", cuantos, a, b);

	// 3. Rellena un vector de 10 elementos con los valores introducidos por el usuario
	//      posicion 0: <34>
	//      posicion 1: <31>
	//      ...
	//      posicion 9: <31>
	//  - Imprime el vector anterior
	// DONE
	int vec3[10];
	for (int i = 0; i < 10; i++)
	{
		printf("posicion %d - numero %d: ", i, i+1);
		scanf("%d", &vec3[i]);
	}
	for (int i = 0; i < 10; i++) 
	{
		printf("%d ", vec3[i]);
	}
	printf("\n");

	// 4. Rellena un vector de 10 elementos con los 10 primeros valores primos!
	int i = 0;
	int testNum = 2;
	int vec03[10];
	while (i < 10) // La i son los numeros primos que encuentra
	{
		if (esPrimo(testNum))
		{
			vec03[i] = testNum;
			printf("%d\n", testNum);
			i++; // Primos encontrados
		}
		testNum++;
	}



	// 5. Rellena un vector de 10 elementos con los valores introducidos por el usuario,
	// los valores que no sean pares se ignoraran
	//      posicion 0: 2
	//      posicion 1: 3
	//      posicion 1: 5
	//      posicion 1: 12
	//      posicion 2: 24
	//      ....

	// Busqueda sequencial
	// Rellena el vector para poder buscar
	char leston[20];
	for (int i = 0; i < 20; i++) 
	{
		leston[i] = rand() % ('Z' - 'A' + 1) + 'A';
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%c ", leston[i]);
	}
	printf("\n");

	char buscada;
	do {
		printf("Introduce la mayuscula a buscar [A..Z]: ");
		scanf(" %c", &buscada);
	} while (buscada < 'A' && buscada > 'Z');
	int posEncontrado = -1; // No es una posicion del vector
	i = 0;
	while (i < 20 && posEncontrado == -1) 
	{
		if (leston[i] == buscada)
			posEncontrado = i;
		else 
			i++;
	}
	if (posEncontrado == -1)
		printf("NO APARECE\n");
	else 
		printf("Encontrado en la posicion %d\n", buscada);


	cuantos = 0;
	for (int i = 0; i < 20; i++)
	{
		if (leston[i] == buscada)
		{
			cuantos++;
		}
	}
	printf("He encontrado %d veces en el vector\n", cuantos);


	return 0;
}
