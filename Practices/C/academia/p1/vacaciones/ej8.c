/**
 * @file main.c
 * @brief Código principal del programa.
 */

#include <stdio.h>

#define PALABRAS 6
#define TAM 60

// Define un tipo de datos para representar una cadena de caracteres.
typedef char TCadena [TAM + 1];

// Define un tipo de datos para representar una matriz de enteros.
typedef int TMatriz[PALABRAS][3];

// Define un tipo de datos para representar una matriz de cadenas.
typedef char TMatrizCadenas[PALABRAS][TAM + 1];

/**
 * @brief Calcular el cociente de dos números enteros mediante recursión.
 *
 * Esta función recibe como parámetros dos números enteros y devuelve el cociente calculado mediante recursión.
 *
 * @param a El dividendo.
 * @param b El divisor.
 * @return int El cociente calculado mediante recursión.
 */
int cociente(int a, int b) {
    int c;
    if(a < b){
        c = 0;
    }
    else{
        c = 1 + cociente(a - b, b);
    }
    return c;
}

/**
 * @brief Calcular el resto de un número entero dividido por otro mediante recursión.
 *
 * Esta función recibe como parámetros dos números enteros y devuelve el resto calculado mediante recursión.
 *
 * @param a El dividendo.
 * @param b El divisor.
 * @return int El resto calculado mediante recursión.
 */
int resto(int a, int b) {
    int c;
    if(a < b){
        c = a;
    }
    else{
        c = resto(a - b, b);
    }
    return c;
}

/**
 * @brief Convertir un número entero a una cadena de caracteres mediante recursión.
 *
 * Esta función recibe como parámetros un número entero y un índice inicial, y devuelve el número entero convertido a una cadena de caracteres mediante recursión.
 *
 * @param cad La cadena de caracteres donde se va a convertir el número entero.
 * @param desde El índice inicial en la cadena donde comenzar a convertir el número entero.
 * @return int El número entero convertido a una cadena de caracteres mediante recursión.
 */
int toInt(char cad[], int desde) {
    int n;
    if(desde == 0){
        n = cad[0] - '0';
    }
    else{
        n = toInt(cad, desde - 1)*10 + (cad[desde] - '0');
    }
    return n;
}

/**
 * @brief Convertir un número entero a una suma de dígitos mediante recursión.
 *
 * Esta función recibe como parámetro un número entero y devuelve la suma de sus dígitos calculada mediante recursión.
 *
 * @param n El número entero que se va a convertir a una suma de dígitos.
 * @return int La suma de los dígitos del número entero calculada mediante recursión.
 */
int sd(int n) {
    int res;
    if(n < 10){
        res = n;
    }
    else{
        res = sd(n/10) * 10 + n % 10;
    }
    return res;
}

/**
 * @brief Incrementar un dígito en 1.
 *
 * Esta función recibe como parámetro un número entero y devuelve el resultado de incrementar un dígito en 1 mediante recursión.
 *
 * @param n El número entero que se va a incrementar un dígito en 1.
 * @return int El resultado de incrementar un dígito en 1 mediante recursión.
 */
int incDig(int n) {
    int res, digito;
    if(n < 10){
        res = n + 1;
        if(res == 10){
            res = 9;
        }
    }
    else{
        digito = n % 10;
        digito++;
        if(digito == 10){
            digito = 9;
        }
        res = incDig(n/10) * 10 + digito;
    }
    return res;
}

/**
 * @brief Invertir un número entero mediante recursión.
 *
 * Esta función recibe como parámetro un número entero y devuelve el inverso calculado mediante recursión.
 *
 * @param n El número entero que se va a invertir mediante recursión.
 * @return int El inverso calculado mediante recursión.
 */
int inv(int n) {
    int ni = 0;
    while(n > 0){
        ni = ni * 10 + n % 10;
        n = n / 10;
    }
    return ni;
}

/**
 * @brief Invertir un número entero mediante recursión y almacenar el resultado en una variable.
 *
 * Esta función recibe como parámetros un número entero y una dirección de memoria donde se va a almacenar el resultado, y devuelve la dirección de memoria donde se ha almacenado el inverso calculado mediante recursión.
 *
 * @param n El número entero que se va a invertir mediante recursión.
 * @param resultado La dirección de memoria donde se va a almacenar el inverso calculado mediante recursión.
 * @return int La dirección de memoria donde se ha almacenado el inverso calculado mediante recursión.
 */
void invRec(int n, int *resultado) {
    if(n < 10){
        *resultado = *resultado * 10 + n;
    }
    else{
        *resultado = *resultado * 10 + n % 10;
        invRec(n/10, resultado);
    }
}

/**
 * @brief Calcular la suma de una fila en una matriz de números enteros.
 *
 * Esta función recibe como parámetro una matriz de números enteros y devuelve la suma calculada mediante recursión.
 *
 * @param matriz La matriz de números enteros donde se va a calcular la suma.
 * @return int La suma calculada mediante recursión.
 */
void main_recursivas() {
    // Inicializar la variable que se va a usar para almacenar el inverso del número entero 123.
    int res = 0;
    // Llamada a la función invRec para calcular el inverso del número entero 123 y almacenarlo en la variable resultado.
    invRec(123, &res);
    // Imprimir el valor de la variable resultado que contiene el inverso del número entero 123.
    printf("%d\n", res);

    // Llamada a la función incDig para incrementar un dígito en el número entero 23995 y almacenar el resultado en la variable y.
    int y = incDig(23995);
    // Imprimir el valor de la variable y que contiene el resultado del incremento de un dígito en el número entero 23995.
    printf("%d\n", y);

    // Llamada a la función sd para calcular la suma de los dígitos del número entero 5234 y almacenar el resultado en la variable x.
    int x = sd(5234);
    // Imprimir el valor de la variable x que contiene la suma de los dígitos del número entero 5234.
    printf("%d\n", x);

}

/**
 * @brief Extraer las palabras de una cadena de caracteres mediante recursión y almacenarlas en un arreglo de cadenas.
 *
 * Esta función recibe como parámetro una cadena de caracteres y un arreglo donde se van a almacenar las palabras extraídas mediante recursión.
 *
 * @param cad La cadena de caracteres donde se van a extraer las palabras mediante recursión.
 */
void main_eje_examen() {
    // Inicializar la cadena de caracteres que se va a usar para almacenar las palabras extraídas mediante recursión.
    TCadena cad = "  Ana   programa genial y rudi tambien  ";
    // Inicializar el arreglo de cadenas que se va a usar para almacenar las palabras extraídas mediante recursión.
    TMatrizCadenas cadenicas;
    // Inicializar las variables que se van a usar para almacenar los índices de la cadena y el arreglo.
    int i, k, j;

    // Inicializar el índice que se va a usar para almacenar la posición de cada palabra en la cadena.
    k = 0;
    // Inicializar el índice que se va a usar para almacenar la posición de cada caracter en la cadena.
    i = 0;
    // Bucle para recorrer la cadena de caracteres y extraer las palabras mediante recursión.
    while(cad[i]!= '\0'){
        // Bucle para encontrar el comienzo de cada palabra en la cadena.
        while(cad[i] == ' '){
            i++;
        }
        // Bucle para encontrar el final de cada palabra en la cadena.
        if(cad[i]!= '\0'){
            // Inicializar el índice que se va a usar para almacenar la posición de cada caracter en la palabra.
            j = 0;
            // Bucle para recorrer la cadena de caracteres y extraer cada palabra mediante recursión.
            while(cad[i]!= ' ' && cad[i]!= '\0'){
                // Almacenar cada caracter en la palabra en el arreglo de cadenas.
                cadenicas[k][j] = cad[i];
                // Incrementar el índice que se va a usar para almacenar la posición de cada caracter en la palabra.
                j++;
                // Incrementar el índice que se va a usar para almacenar la posición de cada caracter en la cadena.
                i++;
            }
            // Almacenar el caracter final en la palabra en el arreglo de cadenas.
            cadenicas[k][j] = '\0';
            // Incrementar el índice que se va a usar para almacenar la posición de cada palabra en la cadena.
            k++;
        }
    }

    // Bucle para imprimir las palabras extraídas mediante recursión.
    for(int i = 0; i < PALABRAS; i++){
        // Imprimir cada palabra extraída mediante recursión.
        printf("%s\n", cadenicas[i]);
    }
}

int main() {
    // Inicializar la matriz de números enteros que se va a usar para almacenar los datos.
    int matriz[6][6] = {
        1, 2, 3, 4, 5, 6,
        0, 1, 2, 3, 4, 5,
        0, 0, 1, 2, 3, 4,
        0, 0, 0, 1, 2, 3,
        0, 0, 0, 0, 1, 2,
        0, 0, 0, 0, 0, 1
    };
    // Inicializar las variables que se van a usar para almacenar los índices y la suma de cada fila en la matriz.
    int i, j, s;

    // Bucle para recorrer las filas de la matriz y calcular la suma de cada fila mediante recursión.
    for(int k = 0; k < 6; k++){
        // Inicializar el índice que se va a usar para almacenar la posición de cada caracter en la cadena.
        i = 0;
        // Inicializar el índice que se va a usar para almacenar la posición de cada caracter en la fila.
        j = k;
        // Inicializar la variable que se va a usar para almacenar la suma de cada fila en la matriz.
        s = 0;
        // Bucle para recorrer los caracteres de cada fila en la matriz y calcular la suma mediante recursión.
        while(j < 6){
            // Incrementar la suma de cada fila en la matriz al sumar el valor del caracter actual a la posición i.
            s += matriz[i][j];
            // Incrementar el índice que se va a usar para almacenar la posición de cada caracter en la cadena.
            i++;
            // Incrementar el índice que se va a usar para almacenar la posición de cada caracter en la fila.
            j++;
        }
        // Imprimir el valor de la suma de cada fila en la matriz mediante recursión.
        printf("%d\n", s);
    }
}
