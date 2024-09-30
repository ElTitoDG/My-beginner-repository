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
        printf("Datos introducidos dentro del limite\n");
        if (despachoOrigen < despaschoDestino)
        {
            if (despaschoDestino - despachoOrigen < 60 - despaschoDestino+despachoOrigen)
                printf("%d, creciente\n", despaschoDestino-despachoOrigen);
            else
                printf("%d, decreciente\n", 60-despaschoDestino+despachoOrigen);
        } else
        {
            if (despachoOrigen - despaschoDestino < 60 - despachoOrigen+despaschoDestino)
                printf("%d, decreciente\n", despachoOrigen - despaschoDestino);
            else
                printf("%d, creciente\n", 60-despachoOrigen+despaschoDestino);
        }
    }
    return EXIT_SUCCESS;
}