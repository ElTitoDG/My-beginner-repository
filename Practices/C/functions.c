#include<stdio.h>
#include<stdlib.h>


int main() {

    printf("Top");
    sayHi("Julian", 16);
    printf("Bottom");
    return 0;
}

//void doesn't return anything
void sayHi(char name[], int age){ 
    printf("Hi %s, you are %d", name, age);
}