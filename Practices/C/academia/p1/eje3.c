#include <stdio.h>
#include <math.h>

int main()
{
    float radio, area, perimetro;

    printf("Radio (en metros): ");
    scanf("%f", &radio);

    area = M_PI * radio * radio;

    printf("Area: %.2f\n", area);

    return 0;
}