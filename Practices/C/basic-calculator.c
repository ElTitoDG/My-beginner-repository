#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double num1, num2;

    printf("Enter your first number: ");
    scanf("%lf", &num1); //use for %lf for float number in scanf

    printf("Enter your second number: ");
    scanf("%lf", &num2);

    printf("Result: %f", num1 + num2);
    return 0;
}