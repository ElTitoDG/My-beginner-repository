#include<stdio.h>
#include<stdlib.h>


//other way to call funtions
double cube(double num);

int main() {

    printf("Answer: %.2f", cube(3.0));

    return 0;
}

double cube(double num) {
    double result = num * num * num;
    return result;
}