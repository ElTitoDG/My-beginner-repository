/**
 * @file ej4.c
 * @brief Ejercicio 4: funciones matemáticas y recursivas.
 */

#include <stdlib.h>
#include <stdbool.h>

// Definir el tamaño del vector de chars y el arreglo de contadores
#define TAM1 50
#define TAM2 10

// Definir tipos adicionales para el vector de chars y el arreglo de contadores
typedef char TVector[TAM1];
typedef int TContenedores[TAM2];

/**
 * @brief Contar el número total de unos en la representación decimal de un número entero n, utilizando recursión.
 *
 * Esta función recibe como parámetro un número entero y devuelve el número total de unos en su representación decimal.
 *
 * @param n El número entero del cual se desea contar los unos en su representación decimal.
 * @return int El número total de unos en la representación decimal de n.
 */
int contarTotalUnosRecur(int n) {
    int c;
    if (n < 10) {
        // Si n es menor que 10, se cuenta el número de unos en su representación decimal
        if (n == 1)
            c = 1;
        else
            c = 0;
    } else {
        // Si n es mayor o igual que 10, se divide en dos partes: el último dígito y el resto del número
        if (n % 10 == 1)
            c = 1 + contarTotalUnosRecur(n / 10);
        else
            c = contarTotalUnosRecur(n / 10);
    }
    return c;
}

/**
 * @brief Calcular el dígito de control de un número entero largo n, utilizando un peso que disminuye en 1 por cada posición a la izquierda del número.
 *
 * Esta función recibe como parámetro un número entero y devuelve el dígito de control calculado para n.
 *
 * @param n El número entero largo del cual se desea calcular el dígito de control.
 * @return long El dígito de control calculado para n.
 */
long calcularDigitosContro(long n) {
    int digitoControl = -1;
    int digito;
    int peso;

    if (n >= 10000000 && n <= 99999999) {
        peso = 8;
        while (n > 0) {
            digito = n % 10;
            n = n / 10;
            // Calcular el dígito de control utilizando el peso y el dígito actual del número
            digitoControl = digito * peso;
            peso--;
        }
    }
    return digitoControl;
}

/**
 * @brief Contar el número de veces que los dígitos 3 o 5 aparecen en un número entero n, utilizando recursión.
 *
 * Esta función recibe como parámetro un número entero y devuelve el número de veces que los dígitos 3 o 5 aparecen en su representación decimal.
 *
 * @param n El número entero del cual se desea contar las apariciones de los dígitos 3 o 5.
 * @return int El número de veces que los dígitos 3 o 5 aparecen en la representación decimal de n.
 */
int coincidentes(int n) {
    int s;
    if (n < 10) {
        // Si n es menor que 10, se cuenta el número de veces que los dígitos 3 o 5 aparecen en su representación decimal
        if (n == 3 || n == 5)
            s = n;
        else
            s = 0;
    } else {
        // Si n es mayor o igual que 10, se divide en dos partes: el último dígito y el resto del número
        if (n % 10 == 3 || n % 10 == 5)
            s = n % 10 + coincidentes(n / 10);
        else
            s = coincidentes(n / 10);
    }
    return s;
}

/**
 * @brief Contar el número de apariciones de cada dígito en un vector de chars v, utilizando un arreglo de contadores para almacenar los resultados.
 *
 * Esta función recibe como parámetros un vector de chars y un arreglo de contadores, y devuelve el número de apariciones de cada dígito en v.
 *
 * @param v El vector de chars del cual se desea contar las apariciones de cada dígito.
 * @param conts El arreglo de contadores utilizado para almacenar los resultados de las apariciones de cada dígito.
 */
void contarDigitos(TVector v, TContenedores conts) {
    int pos;
    // Inicializar los contadores del arreglo en cero
    for (int i = 0; i < TAM2; i++) {
        conts[i] = 0;
    }
    // Recorrer el vector de chars y contar las apariciones de cada dígito
    for (int i = 0; i < TAM1; i++) {
        pos = v[i] - '0';
        conts[pos]++;
    }
}

/**
 * @brief Rellenar el vector de chars numericos con valores aleatorios entre 0 y 9.
 *
 * Esta función recibe como parámetro un vector de chars y rellena sus elementos con valores aleatorios entre 0 y 9.
 *
 * @param v El vector de chars que se va a rellenar con valores aleatorios.
 */
void fillRandom(TVector v) {
    for (int i = 0; i < TAM1; i++) {
        v[i] = rand() % 10 + '0';
    }
}

/**
 * @brief Calcular el resultado de una función matemática basada en un número entero n.
 *
 * Esta función recibe como parámetro un número entero y devuelve el resultado calculado para n.
 *
 * @param n El número entero del cual se desea calcular el resultado de la función matemática.
 * @return int El resultado calculado para n.
 */
int programin(int n) {
    int s, digito;
    if (n < 10) {
        // Si n es menor que 10, se calcula el resultado de la función matemática dependiendo del valor de n
        if (n == 0)
            s = 1;
        else {
            if (n % 3 == 0)
                s = n * 2;
            else
                s = n;
        }
    } else {
        // Si n es mayor o igual que 10, se divide en dos partes: el último dígito y el resto del número
        digito = n % 10;
        if (digito == 0)
            s = 1 * programin(n / 10);
        else {
            if (digito % 3 == 0)
                s = digito * 2 * programin(n / 10);
            else
                s = digito * programin(n / 10);
        }
    }
    return s;
}

/**
 * @brief Buscar la posición de un dígito específico en un número entero n, utilizando recursión.
 *
 * Esta función recibe como parámetros un número entero y un dígito entero, y devuelve la posición del dígito específico en n.
 *
 * @param n El número entero del cual se desea buscar la posición de un dígito específico.
 * @param digi El dígito entero que se desea buscar en la representación decimal de n.
 * @return int La posición del dígito específico en la representación decimal de n, o -1 si no se encuentra.
 */
int buscarPosRecur(int n, int digi) {
    int pos = -1;
    if (n < 10) {
        // Si n es menor que 10, se busca el dígito específico en su representación decimal
        if (n == digi)
            pos = 1;
        else
            pos = -1;
    } else {
        // Si n es mayor o igual que 10, se divide en dos partes: el último dígito y el resto del número
        if (n % 10 == digi)
            pos = 1;
        else {
            pos = buscarPosRecur(n / 10, digi);
            if (pos!= -1) {
                pos++;
            }
        }
    }
    return pos;
}

/**
 * @brief Verificar si un número entero n es mayor que su suma de dígitos, utilizando recursión.
 *
 * Esta función recibe como parámetros un número entero y una suma de dígitos, y devuelve true si n es mayor que su suma de dígitos, false en caso contrario.
 *
 * @param n El número entero del cual se desea verificar si es mayor que su suma de dígitos.
 * @param sd La suma de dígitos del número entero n.
 * @return bool True si n es mayor que su suma de dígitos, false en caso contrario.
 */
bool esMayorRecur(int n, int sd) {
    // Implementar la lógica necesaria para verificar si n es mayor que su suma de dígitos
}

/**
 * @brief Obtener el carácter mayor en una cadena de chars, utilizando recursión.
 *
 * Esta función recibe como parámetros una cadena de chars y un índice inicial, y devuelve el carácter mayor en la cadena.
 *
 * @param cadena La cadena de chars del cual se desea obtener el carácter mayor.
 * @param desde El índice inicial en la cadena donde comenzar a buscar el carácter mayor.
 * @return char El carácter mayor en la cadena de chars, o '\0' si la cadena está vacía.
 */
char getMayorRecur(char cadena[], int desde) {
    char mayor;

    if (cadena[desde] == '\0') {
        mayor = '\0';
    } else {
        mayor = getMayorRecur(cadena, desde + 1);
        if (cadena[desde] > mayor) {
            mayor = cadena[desde];
        }
    }

    return mayor;
}

/**
 * @brief Obtener el dígito mayor en un número entero, utilizando recursión.
 *
 * Esta función recibe como parámetro un número entero y devuelve el dígito mayor en n.
 *
 * @param n El número entero del cual se desea obtener el dígito mayor.
 * @return int El dígito mayor en n, o n si n es menor que 10.
 */
int getMayorDigitoRecur(int n) {
    int mayor;

    if (n < 10) {
        // Si n es menor que 10, es el dígito mayor por defecto
        mayor = n;
    } else {
        // Si n es mayor o igual que 10, se divide en dos partes: el último dígito y el resto del número
        mayor = getMayorDigitoRecur(n / 10);
        if (n % 10 > mayor) {
            // Se compara el último dígito de n con el dígito mayor encontrado hasta ahora
            mayor = n % 10;
        }
    }

    return mayor;
}

int main(void) {
    // Implementar el código principal del programa

    return 0;
}
