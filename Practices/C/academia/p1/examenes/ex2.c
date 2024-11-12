#include <stdio.h>

int cuantoApostar(int saldo)
{
	int apuesta;
	do
	{
		printf("Cuanto quieres apostar [0..%d]: ", saldo);
		scanf("%d", &saldo);
	} while (apuesta < 0 || apuesta > 100);
	return apuesta;
}

char caraOCruz(int apuesta)
{
	char eleccion;

	do
	{
		printf("Cara(c) o Cruz(X): ");
		scanf(" %c", &eleccion);
	} while (eleccion != 'x' && eleccion != 'c');

	if (eleccion == 'c')
		printf("has apostado %d monedas a cara\n", apuesta);
	else
		printf("has apostado %d monedas a cruz\n", apuesta);

	return eleccion;
}

char preguntar()
{
	char res;
	do
	{
		printf("Respuesta: ");
		scanf(" %c", &res);
	} while (res != 's' && res != 'n');
	return res;
}

int main()
{
	int saldo = 100;
	int apuesta; 
	char res, eleccion;

	res = preguntar();
	while (res == 's')
	{
		apuesta = cuantoApostar(saldo);
		eleccion = caraOCruz(apuesta); 



		res = preguntar();
	}

	return 0;
}
