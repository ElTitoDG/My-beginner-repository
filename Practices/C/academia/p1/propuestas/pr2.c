#include <stdio.h>
#include <math.h>

int main()
{
    int radio, altura;
    
    printf("Introduce el radio y la altura del cilindro (radio, altura): ");
    scanf("%d, %d", &radio, &altura);

    if (radio < 0 || altura < 0)
    {
        fprintf(stderr, "Ninguno de los datos proporcionados pueden ser negatibos");
        return 1;
    }

    double volumen = M_PI * pow(radio, 2) * altura;

    printf("El volumen del cilindro es: %f\n", volumen); 
    return 0;
}