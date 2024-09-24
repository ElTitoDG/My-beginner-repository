#include <stdio.h>

int main() {
    int hora1, minuto1, hora2, minuto2;
    int total_minutos1, total_minutos2, diferencia_minutos;

    // Pedir la primera hora
    printf("Introduce la primera hora (hora y minutos separados por espacio): ");
    scanf("%d %d", &hora1, &minuto1);

    // Pedir la segunda hora
    printf("Introduce la segunda hora (hora y minutos separados por espacio): ");
    scanf("%d %d", &hora2, &minuto2);

    // Convertir horas y minutos a minutos totales
    total_minutos1 = hora1 * 60 + minuto1;
    total_minutos2 = hora2 * 60 + minuto2;

    // Calcular la diferencia entre las dos horas
    diferencia_minutos = total_minutos2 - total_minutos1;

    // Mostrar la diferencia en horas y minutos
    printf("La diferencia entre las dos horas es: %d hora(s) y %d minuto(s)\n",
           diferencia_minutos / 60, diferencia_minutos % 60);

    if (total_minutos1 > total_minutos2) 
        printf("La mas tardia es: %d:%d", hora1, minuto1);
    else 
        printf("La mas tardia es: %d:%d", hora2, minuto2);

    return 0;
}