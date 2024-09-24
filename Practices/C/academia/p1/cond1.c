#include <stdio.h>

int main()
{
    int x;
    printf("x?: ");
    scanf("%d", &x);

    if (x >= 0)
    {
        printf("es mayor que 0\n");
        printf("que bien\n");
        x = x + 10;
    }
    else { printf("numero negativo\n"); }

    printf("%d acabando el programa\n");

    return 0;
}