#include <stdio.h>

#define PB 82
#define DESC1 0.25
#define DESC2 0.10
#define DESC3 0.05

int main()
{
    int ca1, ca2, ca3, aux;
    float precio;

    printf("Introduce los 3 destinos de las cargas (1..6): ");
    scanf("%d %d %d", &ca1, &ca2, &ca3);

    if (ca1 == ca2 && ca2 == ca3)
        precio = 3 * (PB * (1 - DESC1));
    if (ca1 == ca2 || ca2 == ca3 || ca3 == ca1)
        precio = PB + 2 * (PB * (1 - DESC2));
    if (ca3 < ca2)
    {
        aux = ca3;
        ca3 = ca2;
        ca2 = aux;
    }
    if (ca2 < ca1)
    {
        aux = ca1;
        ca1 = ca2;
        ca2 = aux;
    }
    if (ca3 < ca2)
    {
        aux = ca3;
        ca3 = ca2;
        ca2 = aux;
    }

    if (ca1 == ca2 - 1 && ca2 == ca3 - 1)
        precio = 3 * (PB * (1 - DESC3));
    else
        precio = 3 * PB;

    printf("El precio final es: %f\n", precio);

    return 0;
}

/*
    En el caso de usar else-if, cuando la primara condicion del condicional anidado
    se cumple, los siguientes condicionales no se ejecutan.
    Tener en cuenta para condicionales anidados como a la hora de ordenar numeros
*/