#include<stdio.h>
#include<stdlib.h>

int main() {
    
    /*int age;
    printf("Enter your age: ");
    scanf("%d", &age); //with apersand you get input for age var --POINTER--
    printf("Your are %d years old", age);
    */ 

    char name[20];
    printf("Enter your name: ");
    fgets(name, 20, stdin); //fgets gets multiple characters
    printf("Your naem is: %s", name);

    return 0;
}