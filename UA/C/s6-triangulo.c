#include <stdio.h>
#include <stdlib.h>

void menu();
void triII(int altura);
void triSI(int altura);
void triID(int altura);
void triSD(int altura);
int input();

int main() {
  int op, h;

  menu();
  scanf("%i", &op);

  switch (op) {
  case 1:
    h = input();
    triII(h);
    printf("-------FIN-------\n");
    break;
  case 2:
    h = input();
    triSD(h);
    /** TODO **/
    printf("-------FIN-------\n");
    break;
  case 3:
    h = input();
    triSI(h);
    printf("-------FIN-------\n");
    break;
  case 4:
    h = input();
    triID(h);
    printf("-------FIN-------\n");
    break;
  case 0:
    printf("-------FIN-------\n");
    break;
  }

  return 0;
}

void menu() {

  printf("1. Triangulo Superior Izquierda\n");
  printf("2. Triangulo Superior Derecha\n");
  printf("3. Triangulo Inferior Izquierda\n");
  printf("4. Triangulo Inferior Derecha\n");

  printf("0. Exit\n");

  printf("Seleccione una opcion: ");
}

void triII(int altura) {
  int i, j;
  for (i = 1; i <= altura; i++) {
    printf("Fila %i: ", i);
    for (j = 1; j <= i; j++) {
      printf("x");
    }
    printf("\n");
  }
}

void triSI(int altura) {
  int i, j, k;
  for (i = altura; i >= 1; i--) {
    printf("Fila %i: ", i);
    for (j = 1; j <= i; j++) {
      printf("x");
    }
    printf("\n");
  }
}

void triID(int altura) {
  int i, j, k;
  for (i = 1; i <= altura; i++) {
    for (j = 0; j <= altura - i; j++) {
      printf(" ");
    }
    for (k = 0; k <= altura - j; k++) {
      printf("x");
    }
    printf("\n");
  }
}

void triSD(int altura) {
  int i, j, k;

  for (i = altura; i >= 1; i--) {
    for (j = 0; j <= altura - i; j++) {
      printf(" ");
    }
    for (k = 0; k <= altura - j; k++) {
      printf("x");
    }
    printf("\n");
  }
}

int input() {

  int altura;
  printf("Introduce la altura: ");
  scanf("%i", &altura);
  printf("-----------------\n");

  return altura;
}
