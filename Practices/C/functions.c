#include<stdio.h>
#include<stdlib.h>

//void doesn't return anything
void sayHi(char name[], int age){ 
    printf("Hi %s, you are %d\n", name, age);
}

int main() {

    printf("Top\n");
    sayHi("Julian", 16);
    printf("Bottom\n");
    return 0;
}

