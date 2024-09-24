#include <stdio.h>

int main()
{
    int numero;
    int d1, d2, d3;

    printf("Introduce un numero de 3 digitos: ");
    scanf("%d", &numero);

    d1 = numero % 10;   // 123 % 10 = 3
    numero /= 10;       // 123 / 10 = 12,3
    d2 = numero % 10;   // 12,3 % 10 = 2
    d3 = numero / 10;   // 12,3 / 10 = 1

    printf("Digitos del numero ingresado: %d, %d, %d\n", d1, d2, d3);
    printf("Suma: %d\n", d1+d2+d3);

    return 0;
}