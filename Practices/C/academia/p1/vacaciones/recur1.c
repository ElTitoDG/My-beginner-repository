#include <stdio.h>

// Calcula la suma de los dígitos de un número
int suma_digitos(int n) {
    if (n < 10) return n;
    return n % 10 + suma_digitos(n / 10);
}

// Cuenta la cantidad de dígitos de un número
int contar_digitos(int n) {
    if (n < 10) return 1;
    return 1 + contar_digitos(n / 10);
}

// Cuenta los dígitos pares de un número
int contar_digitos_pares(int n) {
    if (n < 10) return (n % 2 == 0) ? 1 : 0;
    return (n % 10 % 2 == 0 ? 1 : 0) + contar_digitos_pares(n / 10);
}

// Calcula la suma de los múltiplos de x entre x y n
int suma_multiplos(int n, int x) {
    if (n < x) return 0;
    return (n % x == 0 ? n : 0) + suma_multiplos(n - 1, x);
}

// Calcula el factorial de un número
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Imprime los múltiplos de 3 descendentes hasta 0
void imprimir_multiplos3(int n) {
    if (n < 0) return;
    if (n % 3 == 0) printf("%d ", n);
    imprimir_multiplos3(n - 1);
}

// Alterna la impresión de números pares e impares
void alternar_imprimir(int n) {
    if (n == 0) {
        printf("\n");
        return;
    }
    if (n % 2 == 0) printf("%d", n);
    alternar_imprimir(n - 1);
    if (n % 2 == 1) printf("%d", n);
}

// Imprime números en orden ascendente
void imprimir_ascendente(int n) {
    if (n == 0) {
        printf("[0] ");
        return;
    }
    imprimir_ascendente(n - 1);
    printf("%d ", n);
}

// Imprime números en orden descendente
void imprimir_descendente(int n) {
    if (n == 0) {
        printf("[0]\n");
        return;
    }
    printf("%d ", n);
    imprimir_descendente(n - 1);
}

// Menú principal
int main() {
    int opcion, numero, x;
    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Suma de los dígitos de un número\n");
        printf("2. Contar dígitos de un número\n");
        printf("3. Contar dígitos pares de un número\n");
        printf("4. Suma de múltiplos de un número\n");
        printf("5. Factorial de un número\n");
        printf("6. Imprimir múltiplos de 3 descendentes\n");
        printf("7. Alternar impresión de pares e impares\n");
        printf("8. Imprimir números en orden ascendente\n");
        printf("9. Imprimir números en orden descendente\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                printf("Suma de los dígitos: %d\n", suma_digitos(numero));
                break;
            case 2:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                printf("Cantidad de dígitos: %d\n", contar_digitos(numero));
                break;
            case 3:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                printf("Cantidad de dígitos pares: %d\n", contar_digitos_pares(numero));
                break;
            case 4:
                printf("Ingrese el límite superior y el múltiplo (n, x): ");
                scanf("%d %d", &numero, &x);
                printf("Suma de múltiplos: %d\n", suma_multiplos(numero, x));
                break;
            case 5:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                printf("Factorial: %d\n", factorial(numero));
                break;
            case 6:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                imprimir_multiplos3(numero);
                printf("\n");
                break;
            case 7:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                alternar_imprimir(numero);
                printf("\n");
                break;
            case 8:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                imprimir_ascendente(numero);
                printf("\n");
                break;
            case 9:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                imprimir_descendente(numero);
                printf("\n");
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 0);

    return 0;
}
