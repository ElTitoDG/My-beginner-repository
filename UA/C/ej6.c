#include <stdio.h>

int
factorial (int numero)
{

  int resultado = 1;
  int i;

  for (i = 1; i <= numero; i++)
    {
      resultado = resultado * i;
    }
  return resultado;
}

int
main ()
{

  int numero, i;
  int resultado;

  do
    {
      printf ("Introduce un numero para calcular el factorial: ");
      scanf ("%d", &numero);
    }
  while (numero < 0);

  resultado = factorial (numero);

  printf ("%d! = %d\n", numero, resultado);

  return 0;
}
