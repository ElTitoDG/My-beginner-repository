#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int generarNumero() { return rand() % 900 - 100; }

int preguntarNumero(int oportunidades)
{
	int num;
	printf("Te quedan %d oportunidades\n", oportunidades);
	do
	{
		printf("Introduce un numero: ");
		scanf("%d", &num);
	} while (num < 100 || num > 999);
	return num;
}

bool comprobarNumero(int generado, int usuario, int *oportunidades)
{
	int g1, g2, g3;
	int u1, u2, u3;
	int enSuSitio, noEnSuSitio;
	bool acierto;

	g1 = generado / 100;
	g2 = generado % 100 / 10;
	g3 = generado % 10;

	u1 = usuario / 100;
	u2 = usuario % 100 / 10;
	u3 = usuario % 10;

	enSuSitio = 0;
	noEnSuSitio = 0;

	if (u1 == g1)
		enSuSitio++;
	else
		if (u1 == g2 || u1 == g3)
			noEnSuSitio++;
	if (u2 == g2)
		enSuSitio++;
	else
		if (u2 == g1 || u2 == g3)
			noEnSuSitio++;
	if (u3 == g3)
		enSuSitio++;
	else
		if (u3 == g1 || u3 == g2)
			noEnSuSitio++;

	printf("%d estan en la posicion correcta\n", enSuSitio);
	printf("%d no estan en su posicion correcta\n", noEnSuSitio);

	if (enSuSitio == 3)
		acierto = true;
	else 
	{
		*oportunidades -= 1;
		acierto = false;
	}
	
	return acierto;
}

int main()
{	
	int oportunidades = 10; 
	int numUsuario, estan, noEstan;
	bool acierto;

	int generado = generarNumero();

	numUsuario = preguntarNumero(oportunidades);
	acierto = comprobarNumero(generado, numUsuario, &oportunidades);


	printf("Adivina %d\n", generado);

	return 0;
}
