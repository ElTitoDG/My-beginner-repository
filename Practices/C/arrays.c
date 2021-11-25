#include<stdlib.h>
#include<stdio.h>

int main() {

    int luckyNumbers[10]; //array with any element
    //int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
    //inex pos              0  1  2   3   4   5
    luckyNumbers[1] = 200; //with this we can change de element in that index
    printf("%d $", luckyNumbers[1] ); // the number in brackets is de index of the array

    return 0;
}