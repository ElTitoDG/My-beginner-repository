#include <stdio.h>

int main()
{

    int numero;
    int suma, contador;
    float media;


    suma = 0;
    contador = 0;

    do
    {
        printf("Introduce un numero entero: ");
        scanf("%d", &numero);

        if (numero >= 0)
        {
            suma += numero;
            contador++;
        }
    } while (numero >= 0);

    printf("Suma: %d || Contador: %d\n", suma, contador);

    if (contador > 0)
    {
        media = (float)suma/contador;
    }
    else {
        media = 0;
    }

    printf("Media: %f\n", media);


    return 0;
}
