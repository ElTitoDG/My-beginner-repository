#include <stdio.h>

void test1() {
	int i, s, n;

	do {
		printf("n: ");
		scanf("%d", &n);
	} while (n < 0);

	i = 1;
	do {
		s = i * (i + 1) / 2;
		printf("%d", s);
		i++;
	} while (s < n);
	printf("\n");

	if (n == s)
		printf("Es triangulo\n");
	else
		printf("No es triangulo\n");
}

int max3(int a, int b, int c) {
	int max;
	if (a > b || a > c)
		max = a;
	if (b > a || b > c)
		max = b;
	if (c > a || c > b)
		max = c;

	return max;
}

void test2() {
	int n, n_old, pos, digito, ni;

	do {
		printf("n (debe ser mayor que 10): ");
		scanf("%d", &n);
	} while (n < 10);
	
	n_old = n;
	ni = 0;
	while (n > 0) {
		digito = n % 10;
		n = n / 10;
		ni = ni * 10 + digito;
	}

	if (n_old == ni)
		printf("Es capicua\n");
	else
		printf("No es capicua\n");

}

void test3() {
	int n, divisor, sumaDivisores;

	do {
		printf("n: ");
		scanf("%d", &n);
	} while (n < 0);

	sumaDivisores = 0;
	for (divisor = 1; divisor <= n; divisor++) {
		if (n % divisor == 0)
			sumaDivisores += divisor;
	}

	if (sumaDivisores <= 2 * n)
		printf("Es defectivo\n");
	else
		printf("No es defectivo\n");
}


void test4() {
	int inputNum, sumaDiv=0, countDiv=0;

	do {
		printf("Numero? ");
		scanf("%d", &inputNum);
		if (inputNum <= 0)
			printf("El numero tiene que ser mayor que 0\n");
	} while (inputNum <=  0);

	for (int i = 1; i <= inputNum; i++) {
		if (inputNum % i == 0) {
			sumaDiv += i;
			countDiv++;
		}
	}

	printf("Numero=%d, Suma de Divisores=%d, Numero de Divisores=%d\n", inputNum, sumaDiv, countDiv);
}

int main() {

	int a, b, c;
	printf("Introduce tres valores (a b c): ");
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", max3(a, b, c));

	return 0;
}
