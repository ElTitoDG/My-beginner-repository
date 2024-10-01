#include <stdio.h>
#include <stdlib.h>

int main()
{
    int despachoOrigen, despaschoDestino;

    printf("Introduce el despacho de origen: ");
    scanf("%d", &despachoOrigen);

    printf("Introduce el despacho de destino: ");
    scanf("%d", &despaschoDestino);

    if ((despachoOrigen < 1 || despaschoDestino < 1) || (despachoOrigen > 60 || despaschoDestino > 60))
    {
        printf("Datos introducidos fuera del limite\n");
        return EXIT_FAILURE;
    } else 
    {
        if (despachoOrigen < despaschoDestino)
        {
            if (despaschoDestino - despachoOrigen < (60 - despaschoDestino) + despachoOrigen)
                printf("Distancia: %d en sentido directo\n", despaschoDestino - despachoOrigen);
            else
                printf("Distancia: %d en sentido inverso\n", (60-despaschoDestino) + despachoOrigen);
        } else
        {
            if (despachoOrigen - despaschoDestino < (60 - despachoOrigen) + despaschoDestino)
                printf("Distancia %d en sentido inverso\n", despachoOrigen - despaschoDestino);
            else
                printf("Distancia: %d en sentido directo\n", (60-despachoOrigen) + despaschoDestino);
        }
    }
    return EXIT_SUCCESS;
}