#include <stdio.h>
#include <stdlib.h>

// 2020 code
// 0101 code

void pedirCodigo(int *res_cod, int *res_cuantos)
{
	char c;

	do
	{
		c = getchar();
		printf("(DEBUG) Leyendo: %c\n", c);
		if (c != '.')
		{
			(*res_cuantos)++;
			*res_cod = *res_cod * 10 + (c - '0'); // Codigo para pasar un digito en caracter en digito
		}
	} while (c != '.');
}

void limpiarBuffer()
{
	char c;
	
	do 
	{
		c = getchar();
	} while (c != '\n');
}

void mostrarUsuario(int cod)
{
	switch (cod) {
		case 101: // 0101 se interpreta como octal
			printf("Hola Vicente\n");
			break;
		case 2020:
			printf("Hola Marta\n");
			break;
	}
}

// ancho -> 1-9
// alto  -> 1-12
void pedirDim(int *res_alto, int *res_ancho)
{	
	printf("La altura minima es 1 y la maxima es 12\n");
	printf("La anchura minima es 1 y la maxima es 9\n");
	do
	{
		printf("Introduce el alto y el ancho separados por espacios: ");
		scanf("%d %d", res_alto, res_ancho);
	} while (*res_alto < 1 || *res_alto > 12 || *res_ancho < 1 || *res_ancho > 9);
}

void dibujar(int alto, int ancho)
{
	for(int i = 1; i <= ancho + 2; i++)
	{
		printf(".");
	}
	printf("\n");

	for(int i = 1; i <= alto; i++)
	{
		printf(".");
		for (int j = 1; j <= ancho; j++) 
		{
			printf("o");
		}
		printf(".\n");
	}

	for(int i = 1; i <= ancho + 2; i++)
	{
		printf(".");
	}
	printf("\n");
}

int main()
{
	int pin = 0, pin_cuantos = 0, alto, ancho;

	printf("Introduzca el PIN: ");

	pedirCodigo(&pin, &pin_cuantos);
	limpiarBuffer();

	if (pin_cuantos != 4)
		printf("El PIN no tiene el numero correcto de numeros\n");
	else
		mostrarUsuario(pin);

	pedirDim(&alto, &ancho);
	dibujar(alto, ancho);

	return 0;
}
