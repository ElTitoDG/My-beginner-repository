#include <stdio.h>
#include <stdlib.h>

int main() {
  int sum, num1, num2;

  printf("Introduce un numero entre el 1 y el 5: ");
  scanf("%i, %i", &num1, &num2);
  printf("-----------------\n");

  if (num1 >= 1 && num2 <= 5) {
    sum = num1 + num2;

    for (int i = 1; i <= sum; i++) {
      for (int j = 1; j <= i; j++) {
        printf("x");
      }
      printf("\n");
    }
  } else {
    printf("Error");
    return 1;
  }

  printf("-------FIN-------\n");
  return 0;
}
