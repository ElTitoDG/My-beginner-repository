#include <stdio.h>

int main()
{
    float precioNormal;
    int descuento, importeRecibido;

    printf("Precio del producto (€): ");
    scanf("%f", &precioNormal);

    printf("Descuento a aplicar (%%): ");
    scanf("%d", &descuento);

    float total = precioNormal - (((float)descuento/100) * precioNormal); //Tener en cuanta que la division con enteros devuelve enteros
    printf("Total a pagar: %.2f\n", total);
    
    printf("Importe recibido (€): ");
    scanf("%d", &importeRecibido);

    printf("Importe a devolver: %.2f €\n", importeRecibido - total);
}