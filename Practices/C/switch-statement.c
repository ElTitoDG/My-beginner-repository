#include<stdlib.h>
#include<stdio.h>

int main() {

    char grade;

    printf("Test score: ");
    scanf(" %c", &grade);

    switch(grade){
        case 'A': 
            printf("You have pass!");
        break;
        case 'B': 
            printf("You did alright!");
        break;
        case 'C': 
            printf("You did poorly!");
        break;
        case 'D': 
            printf("You did very bad!");
        break;
        case 'F': 
            printf("You failed!");
        break;
        default: 
            printf("Invalid Grade");
    }

    return 0;
}