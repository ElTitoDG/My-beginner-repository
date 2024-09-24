#include <stdio.h>


int main()
{
    int lado;

    printf("Introduce las medidas del lado (en metros): ");
    scanf("%d", &lado);

    if (lado < 0)
    {
        fprintf(stderr, "Error: el lado \e[1m%d\e[m no puede ser negativo\n", lado);
        return 1;
    }

    // Calculo del area del cuadrado
    int area = lado*lado;
    // Calculo del perimetro del cuadrado
    int perimetro = 4*lado;

    printf("Area: %d -|- Perimetro: %d\n", area, perimetro);
}