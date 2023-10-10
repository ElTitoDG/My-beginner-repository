#include <stdio.h>
#include <stdlib.h>

/*
** Cosas ha hacer:
** 1- comprobar fechas, tanto los dias como los meses si es bisiexto el año
*tambien [x]
** 2- en caso de que sea incorrecto pedir al usuario que vuelva a introducir el
*valor []
** 3- imprimir en un formato "largo", es decir: $DIA de $MES de $AÑO []
**
*/

int checkDate(int day, int month, int year) {
  // Esta funcion se encarga de validar unicamente la fecha
  if (year < 0 || (day < 1 && day > 31) || month < 1 || month > 12) {
    printf("Fecha incorrecta\n");
    return 1;
  } else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
             day > 30) {
    printf("Fecha incorrecta\n");
    printf("Este mes solo cuenta con 30\n");
    return 1;
  } else if (month == 2)
    if (year % 4 == 0)
      if (day > 29) {
        printf("Fecha incorrecta\n");
        return 1;
      } else {
        printf("Fecha correcta\n");
        return 0;
      }
    else if (day > 28)
      printf("Fecha incorrecta\n");
    else
      printf("Fecha correcta\n");
  else {
    printf("Fecha correcta\n");
    printf("La fecha es: %d de %d de %d\n", day, month, year);
  }
  return EXIT_SUCCESS;
}

int main() {

  int d, m, y;

  printf("Introduce una fecha con el formato { d-m-a }: ");
  scanf("%d-%d-%d", &d, &m, &y);

  checkDate(d, m, y);

  return 0;
}
