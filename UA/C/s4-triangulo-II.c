#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nfilas, i, j;

    printf("Numuero de filas: ");
    scanf("%i", &nfilas);
    printf("-----------------\n");

    for(i=1; i<=nfilas; i++)
    {
        printf("Fila %d: ", i);
        for (j=nfilas; j>=i; j--)
        {
            printf("x");
        }
        printf("\n");

    }


    printf("-------FIN-------\n");
    return 0;

}
