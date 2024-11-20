#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printArray(int array[], int SIZE)
{
	printf("[");
	for (int i = 0; i < SIZE; i++) {
		printf("%d", array[i]);
		if (i != SIZE - 1)
			printf(", ");
	}
	printf("]\n\n");	
}

void fillRandom(int v[], int SIZE, int min, int max)
{
	for (int i = 0; i < SIZE; i++) {
		v[i] = rand() % (max - min + 1) + min;
	}
}

// Basic algos for arrays
int sumar(int v[], int SIZE)
{
	int suma = 0;
	for (int i = 0; i < SIZE; i++) {
		suma += v[i];
	}
	return suma;
}

// Devuele la primera posicion en la que aparece
// el elemento buscado
int buscar_elemento(int v[], int SIZE, int buscado)
{
	int pos = -1;
	int i = 0;

	while (i < SIZE && pos == -1) {
		if (v[i] == buscado)
			pos = i;
		else
			i++;
	}
	return pos;
}

int buscar_menor(int v[], int SIZE) {
	int menor;

	menor = v[0]; // suponemos que el primero es el menor
	for (int i = 1; i < SIZE; i++) {
		if (v[i] < menor)
			menor = v[i];
	}
	return menor;
}

int menor_sup_media(int v[], int SIZE)
{
	float media = (float)sumar(v, SIZE)/SIZE;

	// el primer elemnto que supere la media
	// seguro que es menor que 31
	int menor = 31;

	for (int i = 0; i < SIZE; i++) {
		if (v[i] > media && v[i] < menor)
			menor = v[i];
	}
	return menor;
}

/*
     n = 90
     divisor = 2 => primo = false
     n = 11
     divisor = 2, 3, 4, 5, 6 y para => primo = true

    n = 25
    divisor     es
    ----------------------
    2           true
    ======================  2 <= 12 && true == true
    3           true
    ======================= 3 <= 12 && true == true
    4           true
    ======================= 4 <= 12 && true == true
    5           false
    ======================= 5 <= 12 && false == true

    n = 7
    divisor

    ====================
    2
    3
    ==================== es se quedo como true
*/

bool esPrimo(int n) {

	bool es = false;
    	int divisor;

	if(n > 1) {

		es = true; // supongo que es primo
        	divisor = 2;

        	while(divisor <= n/2 && es == true) {

            		if(n % divisor == 0)
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


	// Extra
	printf("----EXTRA----\n");
	int vecEx[10];
	fillRandom(vecEx, 10, 20, 30);
	printArray(vecEx, 10);

	// ejercicio 1.
	// almacena en un vector de 20 elementos, los 20 primeros numeros de la serie de fibonacci.
	// 1 1 2 3 5 8 13 ... 
	// DONE
	printf("----EJERCICIO 1.----\n\n");
	int vec1[20];
	vec1[0] = 0;
	vec1[1] = 1;
	for (int i = 2; i < 20; i++) {
		vec1[i] = vec1[i-1] + vec1[i-2];	
	}
	
	printArray(vec1, 20);

	// ejercicio 2.
	// Relllena un vector de la siguiente forma
	// 2 1 4 3 6 5 8 7 10 9 12 11
	// DONE
	printf("----EJERCICIO 2.----\n");
	int vec2[12];
	for (int i = 0; i < 12; i++) {
		if (i % 2 == 0)
			vec2[i] = i + 2;
		else
			vec2[i] = i;
	}

	printArray(vec2, 12);

	// ejercicio 3
	// Rellena un vector con valores aleatorios entre 1 y 30.
	// Imprime el valor mas pequeÃ±o que supere el valor medio.
	// DONE
	printf("----EJERCICIO 3.----\n");
	int vec3[30];
	int media, total = 0, min_media = 31;;
	for (int i = 0; i < 30; i++) {
		vec3[i] = rand() % 30 + 1;
		total += vec3[i];
	}
	media = (float)total / 30;

	printArray(vec3, 30);

	for (int i = 0; i < 30; i++) {
		if (vec3[i] > media && vec3[i] < min_media)
			min_media = vec3[i];
	}

	if (min_media == 31)
		printf("No hay valores mayores a la media\n");
	else
		printf("El valor mas pequeño que supera la media es: %d\n", min_media);

	// ejercicio 4.
	// 1. rellena un vector A de 30 elementos con valores aleatorios entre 1 y 20
	// 2. rellena otro vector B de 5 elementos con valores introducidos por el usuario entre 1 y 20.
	// 3. muestra para cada elemento del vector B la cantidad de veces que aparece en el vector A.
	// DONE	
	printf("----EJERCICIO 4.----\n\n");
	int vec4a[30];
	int vec4b[5];
	
	for (int i = 0; i < 30; i++) {
		vec4a[i] = rand() % 20 + 1;
		if (i < 5)
		{
			printf("Introduce un valor entre 1 y 20 en el segudo vector en la posicion %d: ", i);
			scanf("%d", &vec4b[i]);
		}
	}

	printArray(vec4a, 30);	
	printArray(vec4b, 5);	

	int cuantos = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 30; j++) {
			if (vec4b[i] == vec4a[j])
				cuantos++;
		}
		printf("El elemento de vec4b %d aparece %d en la vec4a\n", vec4b[i], cuantos);
		cuantos = 0;
	}
	return 0;
}
