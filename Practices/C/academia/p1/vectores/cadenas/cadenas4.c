#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define KTAM 50
typedef char TCadena[KTAM];

// Propuesto 1. Inverite el contenido de la cadena
// pasada como parametro.

//                 i  j = 4 - 1 (the last position is not the size of the string)
//                 0  3
// Si entra cad = "hola"
//
//                  ij
//                 0123
//                 aolh
//
//                  ji
//                 0123
//                 aloh

// tendra que quedarse cad como = "aloh"
void invertir(TCadena cad)
{
    int i, j, aux;
    i = 0;
    j = strlen(cad) - 1;
    while (i < j) {
        aux    = cad[i];
        cad[i] = cad[j];
        cad[j] = aux;
        i++;
        j--;
    }
}

// Propuesto 2. Almacena en el vector
// que te pasan como parametro la cantidad
// de veces que aparece cada vocal.
// Si entra la cadena "hola que tal ieee"
// el vector de contadores quedara como:
//      0 1 2 3 4
//      2 3 1 1 1
// (2 aes, 3 ees, 1 i, 1 o, 1 u)
#define KCONTADORES 5
typedef int TContadores[KCONTADORES];
void        contar(TCadena cad, TContadores contas)
{
    int i;

    for (i = 0; i < KCONTADORES; i++) {
        contas[i] = 0;
    }

    // a e i o u
    // 0 1 2 3 4
    // 0 0 0 0 0

    //           1111111
    // 01234567890123456
    // hola que tal ieee
    i = 0;
    while (cad[i] != '\0') {
        switch (cad[i]) {
            case 'a':
            case 'A':
                contas[0]++;
                break;
            case 'e':
            case 'E':
                contas[1]++;
                break;
            case 'I':
            case 'i':
                contas[2]++;
                break;
            case 'o':
            case 'O':
                contas[3]++;
                break;
            case 'u':
            case 'U':
                contas[4]++;
                break;
        }
        i++;
    }
}

// Propuesto 3.
// almacena en impares, los valores impares
// del vector v, y devuelve la cantidad
// de elementos impares almacenados.
// 2 22 2 2 2 2 2 2 2 2 7
// i i  i i i i i i i i i

//   ni
// 7
int sacaImpares(int v[], int nv, int impares[])
{
    int numImpares;

    numImpares = 0; // impares que llevo almacenados en impares, siguiente posicion a modificar :)
    for (int i = 0; i < nv; i++) {
        if (v[i] % 2 != 0) {
            impares[numImpares] = v[i];
            numImpares++;
        }
    }
    return numImpares;
}

// Propuesto 4.
// intercambia los elementos del vector v
// de 2 en 2. Ejemplos de lo que entra y como
// queda:

//        i     i
//   v = {1, 2, 3, 4} => v = {2, 1, 4, 3}
//   v = {1, 2, 3, 4, 5} => v = {2, 1, 4, 3, 5}
void interSwap(int v[], int nv)
{
    int aux;

    for (int i = 0; i < nv - 1; i += 2) {
        aux      = v[i]; // aux = v[0]   //    aux = v[2]
        v[i]     = v[i + 1];
        v[i + 1] = aux;
    }
}

// Propuesto 5.
#define N 8
typedef int TCuadrada[N][N];

// Rellena la matriz de la siguiente forma
//      1 1 2 2
//      1 1 2 2
//      3 3 4 4
//      3 3 4 4
// pinesa que tiene que funcionar para cualquier
// valor de N par y que se dibujaran siempre
// 4 cuadrantes.

//
//      0 1 2 3 4 5
//  =======================
//      1 1 1 2 2 2  || 0
//      1 1 1 2 2 2  || 1
//      1 1 1 2 2 2  || 2
//      3 3 3 4 4 4  || 3
//      3 3 3 4 4 4  || 4
//      3 3 3 4 4 4  || 5
//
void rellenaCuadrantes(TCuadrada cuadrada)
{ // N = 6
    int filaInicio, columnaInicio;
    for (int cua = 0; cua <= 3; cua++) {
        if (cua < 2) {
            filaInicio = 0;
        }
        else {
            filaInicio = N / 2;
        }
        if (cua % 2 == 0) {
            columnaInicio = 0;
        }
        else {
            columnaInicio = N / 2;
        }
        for (int i = filaInicio; i < N / 2 + filaInicio; i++) {
            for (int j = columnaInicio; j < N / 2 + columnaInicio; j++) {
                cuadrada[i][j] = cua + 1;
            }
        }
    }
}

// Devuelve cierto si la matriz cuadrada
// pasada como parametro es simetrica
// A[i][j] == A[j][i]
//
//     0 1 2 3 4
//  0  . 1 1 1 1
//  1  1 . 2 2 2
//  2  1 2 . 3 3
//  3  1 2 3 . 4
//  4  1 2 3 4 .
//

bool esSimetrica(TCuadrada cuadrada)
{
    bool es = true;
    for (int i = 0; i < N && es == true; i++) {
        for (int j = 0; j < i && es == true; j++) { // paro en i, solo recorro por debajo de la diagonal P
            if (cuadrada[i][j] != cuadrada[j][i]) {
                es = false;
            }
        }
    }
    return es;
}

/*
Matrices:
    * Leer, imprimir, rellenar random, sumar filas, sumar columnas, maximo, minimo
    de toda la matriz o de cada fila.
*/

int main()
{
    char        cadena[]  = "holanegro";
    char        cadena2[] = "las vocales molan mas que las vacas";
    TContadores contadores; // int contadores[5];
    invertir(cadena);
    printf("En el main %s\n", cadena);

    char vocs[] = "aeiou";
    contar(cadena2, contadores);
    for (int i = 0; i < KCONTADORES; i++) {
        printf("%c => %d\n", vocs[i], contadores[i]);
    }

    int numeros[20] = {12, 3, 2, 12, 12, 12, 9};
    int impares[20];
    int ni;
    ni = sacaImpares(numeros, 7, impares);
    printf("Los numeros impares extraidos son:\n");
    for (int i = 0; i < ni; i++) {
        printf("%d ", impares[i]);
    }
    printf("\n");

    printf("Matriz cuadrada recorrida por cuadrantes\n");
    TCuadrada cuadrada;
    rellenaCuadrantes(cuadrada);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", cuadrada[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
    return 0;
}
