#include <stdio.h>

int main()
{
    char operador;
    int n1, n2, resultado;

    printf("Introduce un operador: ");
    scanf(" %c", &operador);

    n1 = 10;
    n2 = 5;

    if (operador == '+' || operador == '-')
    {
        if (operador == '+')
            resultado = n1 + n2;
        else if (operador == '-')
            resultado = n1 - n2;
    } else
        printf("operador incorrector\n");

    printf("Resultado de la operacion entre 10 y 5: %d\n", resultado);

    return 0;
}