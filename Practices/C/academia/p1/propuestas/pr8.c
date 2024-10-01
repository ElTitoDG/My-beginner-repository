#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tam, top;
    float precioFinal;

    printf("Introduce el tamaño del helado (P/G): ");
    scanf("%c", &tam);

    printf("Tipo de topping (F/D/S): ");
    scanf(" %c", &top);

    if (tam == 'P')
    {
        if (top == 'F')
            printf("El precio del helado es: %.2f\n", 1.75 + 0.50);
        if (top == 'D')
            printf("El precio del helado es: %.2f\n", 1.75 + 0.35);
        if (top == 'S')
            printf("El precio del helado es: %.2f\n", 1.75 + 0.30);
    } else if (tam == 'G')
    {
        if (top == 'F')
            printf("El precio del helado es: %.2f\n", 2.20 + (2*0.50));
        if (top == 'D')
            printf("El precio del helado es: %.2f\n", 2.20 + (2*0.35));
        if (top == 'S')
            printf("El precio del helado es: %.2f\n", 2.20 + (2*0.30));
    }
    return EXIT_SUCCESS;
}