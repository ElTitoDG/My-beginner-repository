#include <stdio.h>

void dibujar(char carac, int n)
{
    int  cars = n;
    int space = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        for (int j = 1; j <= cars; j++) {
            printf("%c", carac);
        }
        cars--;
        space++;
        printf("\n");
    }
}

void dibujo2(char carac, int n)
{
    int space = n - 1;
    for (int i = 1; i <= n; i++) {
        // imprimo espacios
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        // imprimimos carac
        for (int j = 1; j <= i; j++) {
            printf("%c", carac);
        }
        space--;
        printf("\n");
    }
}

void dibujo3(char carac, int n)
{
    int space = n - 1, asterics = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        for (int j = 1; j <= asterics; j++) {
            printf("%c", carac);
        }
        printf("\n");
        space--;
        asterics += 2;
    }
}

void dibujo4(char carac, int n)
{

}

int main()
{
    dibujar('#', 5);
    //printf("\n\n");
    dibujo2('#', 5);

    return 0;
}
