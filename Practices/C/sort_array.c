#include <stdio.h>

//Bubble Sort

void sort(char array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(char array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ", array[i]);
    }
}

int main()
{

    int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    char array2[] = {'F', 'A', 'D', 'B', 'C'};
    int size = sizeof(array2)/sizeof(array2[0]);


    sort(array2, size);
    printArray(array2, size);

    return 0;
}
