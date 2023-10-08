#include <stdio.h>
#include <math.h>

int main()
{

    float radio, altura, volumenVaso, litrosSobrantes;
    int cantidadVasos;

    // Solicitar al usuario el radio y la altura del vaso
    printf("Ingrese la altura y el radio del vaso (en centímetros): ");
    scanf("%f %f", &altura, &radio);


    // Calcular el volumen de un vaso cilíndrico
    volumenVaso = M_PI * pow(radio, 2) * altura / 1000.0; // Convertir a litros

    // Calcular la cantidad de vasos que se pueden llenar
    cantidadVasos = (int)(5.0 / volumenVaso);

    // Calcular los litros sobrantes
    litrosSobrantes = fmod(5.0, volumenVaso);
    printf("%f\n\n", litrosSobrantes);

    // Mostrar el resultado
    printf("Se pueden llenar { %d } vasos cilíndricos con 5 litros de líquido.\n", cantidadVasos);
    printf("Sobran { %.6f } litros de líquido.\n", litrosSobrantes);

    return 0;
}
