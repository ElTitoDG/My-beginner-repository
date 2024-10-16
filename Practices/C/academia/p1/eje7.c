#include <stdio.h>
#include <stdlib.h>

int main()
{
	char caracter;
	int veces;

	printf("Introduce un caracter: ");
	scanf("%c", &caracter);

	printf("Introduce las veces: ");
	scanf("%d", &veces);

	for (int i = 1; i <= veces; i++)
	{
		printf("%c", caracter);
	}
	printf("\n");
	

	return EXIT_SUCCESS;
}
