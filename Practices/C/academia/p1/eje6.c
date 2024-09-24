#include <stdio.h>

int main()
{
    int cantidad, m1e, m50cent, m5cent, m1cent;

    printf("Intruduce la cantidad a cambiar (en cent): ");
    scanf("%d", &cantidad);

    m1e = cantidad / 100; // Cantidad de euros
    cantidad %= 100;
    printf("%d monedas de 1 euro\n", m1e);
    
    m50cent = cantidad / 50;
    cantidad %= 50;
    printf("%d monedas de 50 cent\n", m50cent);

    m5cent = cantidad / 5;
    cantidad %= 5;
    printf("%d monedas de 5 cent\n", m5cent);

    m1cent = cantidad;
    printf("%d monedas de 1 cent\n", m1cent);

    return 0;
}