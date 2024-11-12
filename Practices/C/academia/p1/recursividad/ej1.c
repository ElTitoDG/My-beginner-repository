#include <stdio.h>

void countDown(int n)
{
	if (n >= 0)
	{
		printf("%d\n", n);
		countDown(n - 1);
	}
}

int factorial(int n)
{
	if (n < 2)
		return 1;

	return (n * factorial(n - 1));
}

int main()
{
	int number;

	printf("Introduce un numero positivo: ");
	scanf("%d", &number);

	countDown(number);


	printf("El factorial del numero %d es %d\n", number, factorial(number));



	return 0;
}
