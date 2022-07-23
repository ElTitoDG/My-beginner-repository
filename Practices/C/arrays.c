#include<stdlib.h>
#include<stdio.h>

int main() {

    //int luckyNumbers[10]; //array with any element
    //int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
    //inex pos              0  1  2   3   4   5
    //luckyNumbers[1] = 200; //with this we can change de element in that index
    //printf("%d $", luckyNumbers[1] ); // the number in brackets is de index of the array

/*
     // 2d Arrays = an array, where each element is an entire array
    // useful if you need a matrix, grid, or table of data

    // First brackets is for the numbers of rows
    // Second brackets is for the numbers of columns
    int numbers[2][3] = {
                          {1, 2, 3},
                          {4, 5, 6}
                       };
      // 2D Array
*/

    int numbers[3][3];

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

    printf("Rows: %d\n", rows);
    printf("Columns: %d\n", columns);

    numbers[0][0] = 1;
    numbers[0][1] = 2;
    numbers[0][2] = 3;
    numbers[1][0] = 4;
    numbers[1][1] = 5;
    numbers[1][2] = 6;
    numbers[2][0] = 7;
    numbers[2][1] = 8;
    numbers[2][2] = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    return 0;
}
