#include <stdio.h>

int leerPositivo()
{
	int valorPos;

	do 
	{
		printf("Introduce un valor positivo: ");
		scanf("%d", &valorPos);

		if (valorPos < 0)
			printf("Error: el valor es negativo\n");
	
	} while (valorPos < 0);
		return valorPos;
}

void sumar_dir(int a, int b, int *s)
{
	*s = a + b;
}

int main()
{
	int valor1, valor2, sumaTotal;

	valor1 = leerPositivo();
	valor2 = leerPositivo();

	sumar_dir(valor1, valor2, &sumaTotal);

	return 0;
}
