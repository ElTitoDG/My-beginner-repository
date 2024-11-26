#include <stdio.h>
#include <stdlib.h>

/*
	int x = 3, y = 23, z = 2;
    	swapSiMenor(x, y); // MAL!!
    	swapSiMenor(&x, &y); // OK  a = &x, b = &y => *a sea x y *b es y
    	printf("%p %p\n", &x, &y); // IMPRIME LAS DIRECCIONES DE LAS VARIBLES OMG!!
    	printf("%d %d\n", x, y); // 23 3
*/

// deja en *a el menor!!!

void swapSiMayor(int *a, int *b) 
{
	int aux;
    	if(*a > *b) {
        	aux = *a;
        	*a = *b;
        	*b = aux;
	}
}



int main()
{

	int vector[5];

	for(int i = 0; i < 5; i++) {

		vector[i] = rand() % 30 + 10; // 10 y 39

	}
    	for(int i = 0; i < 5; i++) {
        	printf("%d ", vector[i]);
    	}
    	printf("\n");

    	// medium dificult!!
	for(int i = 0; i < 5 - 1; i++) { 				// este bucle no se hace para la ultima posicion del vector :) jeje
		for(int j = i + 1; j < 5; j++) { 			// aqui si que llego hasta la ultima posicon del vector
			swapSiMayor(&vector[i], &vector[j]);

            // i    j                                                                        0  1  2  3  4
            // ---------- i < 4, j < 5                                                      21 27 14 20 39
            // 0    1     j < 5                      swapSiMayor(&vector[0], &vector[1]);   21 27 14 20 39
            // 0    2     j < 5                      swapSiMayor(&vector[0], &vector[2]);   14 27 21 20 39
            // 0    3     j < 5                      swapSiMayor(&vector[0], &vector[3]);   14 27 21 20 39
            // 0    4     j < 5                      swapSiMayor(&vector[0], &vector[4]);   14 27 21 20 39
            // ---------- i < 4, j < 5
            // 1    2     j < 5                      swapSiMayor(&vector[1], &vector[2]);   14 21 27 20 39
            // 1    3     j < 5                      swapSiMayor(&vector[1], &vector[3]);   14 20 27 21 39
            // 1    4     j < 5                      swapSiMayor(&vector[1], &vector[4]);   14 20 27 21 39
            // ----------
            // 2    3                                swapSiMayor(&vector[2], &vector[3]);   14 20 21 27 39
            // 2    4                                swapSiMayor(&vector[2], &vector[4]);   14 20 21 27 39
            // ----------
            // 3    4                                swapSiMayor(&vector[3], &vector[4]);   14 20 21 27 39
            // ----------

		}

	}



    	for(int i = 0; i < 5; i++) {

		printf("%d ", vector[i]);

	}

	printf("\n");
	return 0;
}

// intercambia el valor de las variables cuyas direccions pasamos como parametro
void swap(int *v1, int *v2)
{
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}



int main_1()
{

               //   0   1  2  3  4
	int nums[5] = {10, 23, 2, 3, 2};
	int suma, i, p, j;

	suma = nums[0] + nums[1] * nums[4]; // suma = 10 + 23 * 2 = 56
	printf("%d\n", suma); // 56

	nums[1] = suma - 10; // nums[1] = 56 - 10 = 46

    	//   0   1  2  3  4
    	// {10, 46, 2, 3, 2};
    	// desplaza todos los elementos (menos el ultimo) una posicion a la izquierda
    	i = 0;
    	while(i < 3) {
        	nums[i] = nums[i+1];
        	i++;

    	}

 /*                                          nums
  	                        i       0    1  2  3  4
	=================================================
    	i = 0                   0       10  46  2  3  2
    	================================================ 0 < 3 yes
    	nums[0] = nums[1];      0       46  46  2  3  2
    	i++;                    1       46  46  2  3  2
    	================================================ 1 < 3 yes
    	nums[1] = nums[2];      1       46  2   2  3  2
    	i++;                    2       46  2   2  3  2
    	================================================ 2 < 3 yes
    	nums[2] = nums[3]       2       46  2   3  3  2
    	i++                     3       46  2   3  3  2
    	================================================ 3 < 3 no

*/
	i = 0;
	printf("%d ", nums[i]); // printf("%d ", nums[0]);
	i++;                    // i = 1
	printf("%d ", nums[i]); // printf("%d ", nums[1]);
	i++;                    // i = 2
    	printf("%d ", nums[i]); // printf("%d ", nums[2]);
    	i++;                    // i = 3
    	printf("%d ", nums[i]); // printf("%d ", nums[3]);
	i++;                    // i = 4
    	printf("%d ", nums[i]); // printf("%d ", nums[4]);
    	i++;                    // i = 5
    	printf("\n");
    
	// lo mismo de arriba con un bucle.
	i = 0;
    	while(i < 5) {
        	printf("%d ", nums[i]); // printf("%d ", nums[0]);
        	i++;                    // i = 1
    	}

	printf("\n");

	for(i = 0; i < 5; i++) {
        	printf("%d ", nums[i]);
    	}
    	printf("\n");



    	// Que hace este bucle?
	for(i = 0; i < 5; i++) {
        	nums[i] = rand() % 2; // asignarle al valor que hay en la posicion i o 0 o 1.
	}


    	for(int i = 0; i < 5; i++) {
		printf("%d", nums[i]);
	}
    	printf("\n");

    	// Que hace este bucle?
    	//         0  1  2  3  4
    	// nums = {1, 1, 0, 0, 1} => 1 + 8 + 16

    	suma = 0, p  = 1;

    	for(i = 4; i >= 0; i--) {
        	suma = suma + nums[i] * p;
        	// En este punto
        	// i = 4    p = 1   suma = 0 + nums[4] * 1 = 0 + 1 = 1
        	// i = 3    p = 2   suma = 1 + nums[3] * 2 = 1 + 0 = 1
        	// i = 2    p = 4   suma = 1 + nums[2] * 4 = 1 + 0 = 1
        	// i = 1    p = 8   suma = 1 + nums[1] * 8 = 1 + 8 = 9
        	// i = 0    p = 16  suma = 9 + nums[0] * 16 = 9 + 16 = 25
        	p = p * 2;
	}

    	printf("El valor de i aqui es %d\n", i); // -1
    	printf("%d\n", suma);
    	// deja en suma el valor decimal del binario que hay almacenado en nunms.
	
    	int org[7] = {12, 32, 9, 31, 12, 3, 1};
    	i = 0, j = 6;

    	while(i < j) {
        	// org[i] y org[j] son ints!!!
        	// Lo que le paso a swap es la direccion de los enteros que quiero intercambial!!
        	if(org[j] < org[i]) 
            		swap(&org[i], &org[j]); // intercambia el valor de las dos variables
        	i++;
        	j--;
    	}

    	//   0   1  2   3   4  5  6
    	// {12, 32, 9, 31, 12, 3, 1};
    	//  i   j
 	//  0   6       if(org[6] < org[0]) => swap(&org[0], &org[6]); => {1, 32, 9, 31, 12, 3, 12};
    	//  1   5       if(org[5] < org[1]) => swap(&org[1], &org[5]); => {1, 3, 9, 31, 12, 32, 12};
    	//  2   4       if(org[4] < org[2]) => NO.
    	//  3   3 (ya no entro)

    	for(int i = 0; i < 6; i++) {
        	printf("%d ", org[i]);
    	}
    	printf("\n");
    	return 0;
}

