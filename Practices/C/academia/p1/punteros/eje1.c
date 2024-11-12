#include <stdio.h>

int main()
{
	int a, b;
	int *p;

	a = 10;
	p = &a;

	printf("%d | %p\n", a, p);

	return 0;
}
