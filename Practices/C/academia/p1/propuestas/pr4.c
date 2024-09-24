#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float x1, x2;

    printf("Introduce el coeficiente a: ");
    scanf("%f", &a);

    printf("Introduce el coeficiente b: ");
    scanf("%f", &b);

    printf("Introduce el coeficiente c: ");
    scanf("%f", &c);

    // Calculamos la discriminante
    float discriminante = b * b - 4 * a * c;

    // Calculamos las raices
    x1 = (-b + sqrt(discriminante)) / (2 * a);
    x2 = (-b - sqrt(discriminante)) / (2 * a);

    printf("Las raices del polinomio y pundos de corte con el eje X son:\n");
    printf("x1 = %f\n", x1);
    printf("x2 = %f\n", x2);
    return 0;
}