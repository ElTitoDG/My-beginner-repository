/**
 * @file ej3.c
 * @brief Ejercicio 3: impresión de figuras geométricas con asteriscos y espacios.
 */

#include <stdio.h>

/**
 * @brief Dibuja una pirámide de asteriscos.
 *
 * Esta función recibe dos parámetros: un carácter a imprimir y el número de filas para la pirámide.
 * Estamos utilizando una técnica de espacio-a-asterisco para representar las filas de la pirámide.
 *
 * @param carac El carácter a imprimir en cada fila de la pirámide.
 * @param n El número de filas para la pirámide.
 */
void dibujar(char carac, int n) {
    int  cars = n; // Número de asteriscos en la primera fila
    int space = 0; // Número de espacios antes del primer asterisco en cada fila

    for (int i = 1; i <= n; i++) { // Recorro las filas
        for (int j = 1; j <= space; j++) { // Imprimo espacios antes del primer asterisco en cada fila
            printf(" ");
        }
        for (int j = 1; j <= cars; j++) { // Imprimo los asteriscos en cada fila
            printf("%c", carac);
        }
        cars--; // Decremente el número de asteriscos para las siguientes filas
        space++; // Incremento el número de espacios para las siguientes filas
        printf("\n");
    }
}

/**
 * @brief Dibuja una pirámide creciente de asteriscos.
 *
 * Esta función recibe dos parámetros: un carácter a imprimir y el número de filas para la pirámide.
 * La diferencia principal con `dibujar` es que ahora estamos imprimiendo más asteriscos en cada fila,
 * comenzando desde 1 y aumentando hasta `n`.
 *
 * @param carac El carácter a imprimir en cada fila de la pirámide.
 * @param n El número de filas para la pirámide.
 */
void dibujo2(char carac, int n) {
    int space = n - 1; // Número de espacios antes del primer asterisco en cada fila

    for (int i = 1; i <= n; i++) { // Recorro las filas
        for (int j = 1; j <= space; j++) { // Imprimo espacios antes del primer asterisco en cada fila
            printf(" ");
        }
        for (int j = 1; j <= i; j++) { // Imprimo los asteriscos en cada fila
            printf("%c", carac);
        }
        space--; // Decremente el número de espacios para las siguientes filas
        printf("\n");
    }
}

/**
 * @brief Dibuja una pirámide decreciente de asteriscos con un patrón creciente.
 *
 * Esta función recibe dos parámetros: un carácter a imprimir y el número de filas para la pirámide.
 * La diferencia principal con `dibujo2` es que ahora estamos imprimiendo un patrón creciente de asteriscos
 * en cada fila, comenzando desde 1 y aumentando hasta `n`.
 *
 * @param carac El carácter a imprimir en cada fila de la pirámide.
 * @param n El número de filas para la pirámide.
 */
void dibujo3(char carac, int n) {
    int space = n - 1; // Número de espacios antes del primer asterisco en cada fila
    int asterics = 1;   // Número de asteriscos en la primera fila

    for (int i = 0; i <= n; i++) { // Recorro las filas
        for (int j = 1; j <= space; j++) { // Imprimo espacios antes del primer asterisco en cada fila
            printf(" ");
        }
        for (int j = 1; j <= asterics; j++) { // Imprimo los asteriscos en cada fila
            printf("%c", carac);
        }
        printf("\n");
        space--; // Decremente el número de espacios para las siguientes filas
        asterics += 2; // Incremento el número de asteriscos para las siguientes filas
    }
}

/**
 * @brief Inicia el programa principal.
 *
 * Aquí se invocan las funciones de dibujo y se imprime el resultado.
 *
 * @return 0 Si el programa ha ejecutado con éxito.
 */
int main() {
    // Dibujo una pirámide decreciente de asteriscos
    dibujar('#', 5);
    // Dibujo una pirámide creciente de asteriscos
    dibujo2('#', 5);

    return 0;
}
#include <stdio.h>

void dibujar(char carac, int n)
{
    int  cars = n;
    int space = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        for (int j = 1; j <= cars; j++) {
            printf("%c", carac);
        }
        cars--;
        space++;
        printf("\n");
    }
}

void dibujo2(char carac, int n)
{
    int space = n - 1;
    for (int i = 1; i <= n; i++) {
        // imprimo espacios
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        // imprimimos carac
        for (int j = 1; j <= i; j++) {
            printf("%c", carac);
        }
        space--;
        printf("\n");
    }
}

void dibujo3(char carac, int n)
{
    int space = n - 1, asterics = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        for (int j = 1; j <= asterics; j++) {
            printf("%c", carac);
        }
        printf("\n");
        space--;
        asterics += 2;
    }
}

void dibujo4(char carac, int n)
{

}

int main()
{
    dibujar('#', 5);
    //printf("\n\n");
    dibujo2('#', 5);

    return 0;
}
