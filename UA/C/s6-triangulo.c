#include <stdio.h>
#include <stdlib.h>

void menu();
void triII(int altura);

int input();

int main() {
  int op, h;

  menu();
  scanf("%i", &op);

  h = input();

  switch (op) {
  case 1:
    triII(h);
    printf("-------FIN-------\n");
    break;
  case 2:
    printf("Test\n");
    printf("-------FIN-------\n");
    break;
  case 3:
    printf("Test\n");
    printf("-------FIN-------\n");
    break;
  case 4:
    printf("Test\n");
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

  printf("-----------------\n");

  for (int i = 1; i <= altura; i++) {
    printf("Fila %i: ", i);
    for (int j = 1; j <= i; j++) {
      printf("x");
    }
    printf("\n");
  }
}

int input() {
  int altura;
  printf("Introduce la altura: ");
  scanf("%i", &altura);

  return altura;
}
