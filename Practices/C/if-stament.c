#include<stdlib.h>
#include<stdio.h>

int Max(int num1, int num2, int num3) {
    int result;
    
    if(num1 >= num2 && num1 >= num3) {
        result = num1;
    } else if(num2 >= num1 && num2 >= num3){
        result = num2;
    } else {
        result = num3;
    }

    return result;
}


int main() {

    if(!(3 < 2)) {
        printf("True");
    }

    printf("%d", Max(4, 10, 15));

    return 0;
}

/* 
Logical Operators: 
    && --> AND
    || --> OR
    != --> NOT EQUAL
    == --> EQUAL
    ! --> NEG OPERATOR
*/