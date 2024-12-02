#include <stdio.h>
#include <stdlib.h>

#define SIZE 4
#define SIZE2 100

int main()
{
    int puntos[SIZE];

    puntos[0] = 12;
    puntos[1] = puntos[0] + 3;
    puntos[2] = puntos[1] + 2 * puntos[0];
    int i     = 3;
    puntos[i] = 2 * i;

    printf("[");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", puntos[i]);
        if (i != 3)
            printf(", ");
    }
    printf("]\n");

    for (int i = 0; i < SIZE; i++) {
        printf("Introduce el valor en la posición %d: ", i);
        scanf("%d", &puntos[i]);
    }

    printf("[");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", puntos[i]);
        if (i != 3)
            printf(", ");
    }
    printf("]\n");

    int suma = 0;
    for (int i = 0; i < SIZE; i++) {
        suma += puntos[i];
    }
    printf("La suma del vector es: %d\n", suma);

    printf("Rellenando el valor de forma aleatoria\n");
    for (int i = 0; i < SIZE; i++) {
        puntos[i] = rand() % 10;
    }

    printf("[");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", puntos[i]);
        if (i != 3)
            printf(", ");
    }
    printf("]\n");

    int vector[10];
    for (int i = 0; i < 10; i++) {
        vector[i] = rand() % 90 + 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("[%d]: %d", i, vector[i]);
        if (vector[i] % 2 == 0)
            printf("*");
        printf("\n");
    }

    char mapa[SIZE2];
    for (int i = 0; i < SIZE2; i++) {
        mapa[i] = rand() % ('Z' - 'A' + 1) + 'A';
    }

    for (int i = 0; i < SIZE2; i++) {
        printf(" %c", mapa[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }

    char searchChar;
    do {
        printf("Dame una letra: ");
        scanf(" %c", &searchChar);
    } while (searchChar < 'A' || searchChar > 'Z');

    int contador = 0;
    for (int i = 0; i < SIZE2; i++) {
        if (searchChar == mapa[i])
            contador++;
    }

    printf("Lo he encontrado %d veces\n", contador);

    return 0;
}
