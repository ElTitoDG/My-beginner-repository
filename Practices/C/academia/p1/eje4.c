#include <stdio.h>

int main()
{
    int totalMinutos;
    int horas, minutos;

    printf("Introduce la cantidad total de minutos: ");
    scanf("%d", &totalMinutos);

    horas = totalMinutos / 60;
    minutos = totalMinutos % 60;

    printf("Horas: %d, Minutos: %d\n", horas, minutos);
}