#include <stdio.h>

#define kfilas 2
#define kcolumnas 3

typedef int tmatriz[kfilas][kcolumnas];
typedef int tresultado[kcolumnas];

void sumarColum(tmatriz m, tresultado res);

int main()
{
    tmatriz    m;
    tresultado res;

    for (int i = 0; i < kfilas; i++) {
        printf("Introduce los elementos de la fila %d: ", i + 1);
        for (int j = 0; j < kcolumnas; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < kfilas; i++) {
        for (int j = 0; j < kcolumnas; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    sumarColum(m, res);

    printf("Suma de los elementos de las columnas: ");
    for (int i = 0; i < kcolumnas; i++) {
        printf("%d ", res[i]);
    }

    printf("\n");

    return 0;
}

void sumarColum(tmatriz m, tresultado res)
{
    for (int colum = 0; colum < kcolumnas; colum++) {
        res[colum] = 0;
        for (int row = 0; row < kfilas; row++) {
            res[colum] += m[row][colum];
        }
    }
}
