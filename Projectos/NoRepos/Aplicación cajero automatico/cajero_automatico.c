#include<stdlib.h>
#include<stdio.h>

int main()
{
    int saldo_inicial = 1000, opc, password;
    float ingreso, saldo = 0, retiro;

    printf("Introduzca su contraseña: ");
    scanf("%i", &password);

    if (password == 1234)
    {
        printf("Bienvenido a su cuenta, elija una de las siguientes opciones: \n");
        printf("1. Ingresar dinero\n");
        printf("2. Retirar dinero\n");
        printf("3. Salida\n");
        printf("Opcion: ");
        scanf("%i", &opc);

        switch(opc)
        {
            case 1:
                printf("Introduzca la cantidad a ingresar: ");
                scanf("%f", &ingreso);
                saldo = saldo_inicial + ingreso;
                printf("\n");
                printf("Dinero en cuenta: %.2f\n", saldo);
                printf("Gracias por usar nuestros servicios\n");
                printf("\n");
            break;

            case 2:
                printf("Introduzca la cantidad a retirar: ");
                scanf("%f", &retiro);
                if (retiro > saldo_inicial)
                {
                    printf("\n");
                    printf("Cantidad no disponible\n");
                    printf("\n");
                }else
                {
                    saldo = saldo_inicial - retiro;
                    printf("\n");
                    printf("Dinero en cuenta: %.2f\n", saldo);
                    printf("Gracias por usar nuestros servicios\n");
                    printf("\n");
                }
            break;

            case 3: 
                printf("\n");
                printf("Gracias por usar nuestros servicios\n");
                printf("\n");
            break;
        }
    }else
    {
        printf("Contraseña incorrecta, intentelo de nuevo");
        printf("\n");
    }
}