#include <stdio.h>

void triUp(int n) {
	int asteriscos, espacios;

	asteriscos = 1;
	espacios = n - 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= espacios; j++) {
			printf(" ");
		}
		for (int j = 1; j <= asteriscos; j++) {
			printf("*");
		}
		printf("\n");
		asteriscos += 2;
		espacios -= 1;
	}
}


void triDown(int n) {
	int asteriscos, espacios;

	asteriscos = 2 * (n) - 1;
	espacios = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= espacios; j++) {
			printf(" ");
		}
		for (int j = 1; j <= asteriscos; j++) {
			printf("*");
		}
		espacios++;
		asteriscos -= 2;
		printf("\n");
	}
}

int main()
{
	int n, cantidadDivisor;

	printf("n: ");
	scanf("%d", &n);
	triUp(n);
	triDown(n);

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) {
			printf("%d ", i);
			cantidadDivisor++;
		}
	}
	if (cantidadDivisor == 2)
		printf("=> ES PRIMO\n");
	else 
		printf("=> NO ES PRIMO\n");

	printf("\n");

	return 0;
}

/* int main()
{

	int n, asteriscos, espacios;

	printf("n: ");
	scanf("%d", &n);

	asteriscos = 1;
	espacios = n - 1;
	for (int i = 1; i <= n; i++)
	{
		printf("%d %d|", asteriscos, espacios);
		for (int j = 1; j <= espacios; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= asteriscos; j++)
		{
			printf("*");
		}
		for (int j = 1; j <= n; j++)
		{
			printf("%d", j);
		}
		for (int j = 1; j <= asteriscos; j++)
		{
			printf("*");
		}
		printf("\n");
		asteriscos++;
		espacios--;
	}


	return 0;
} */
