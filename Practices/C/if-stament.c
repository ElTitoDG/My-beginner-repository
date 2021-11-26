#include<stdlib.h>
#include<stdio.h>

int Max(int num1, int num2) {
    int result;
    if(num1 > num2){
        result = num1;
    } else {
        result = num2;
    }
}


int main() {

    printf("%d", Max(4, 10));

    return 0;
}