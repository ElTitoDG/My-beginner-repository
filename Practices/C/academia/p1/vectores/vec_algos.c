#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KROWS 2
#define KCOLUMS 3
#define KSIZE 50
typedef int TMatrix[KROWS][KCOLUMS];
typedef int TResult[KCOLUMS];
typedef char TString[KSIZE];

// Fuctios to use with arrays
void printArray(int array[], int SIZE)
{
	printf("[");
	for (int i = 0; i < SIZE; i++) {
		printf("%d", array[i]);
		if (i != SIZE - 1)
			printf(", ");
	}
	printf("]\n\n");
}

void fillRandom(int array[], int SIZE, int min, int max)
{
	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % (max - min + 1) + min;
	}
}

int arraySum(int array[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += array[i];
	}
	return sum;
}

int posFirstSearchElement(int array[], int SIZE, int searchNum)
{
	int pos
		= -1;
	int i = 0;

	while (i < SIZE && pos == -1) {
		if (array[i] == searchNum)
			pos = i;
		else
			i++;
	}
	return pos;
}

int searchLower(int array[], int SIZE)
{
	int lower;
	
	lower = array[0]; // Assume the first is the lower of the array
	for (int i = 0; i < SIZE; i++) {
		if (array[i] < lower)
			lower = array[i];
	}
	return lower;
	
}

int lowerSupAverage(int array[], int SIZE, int maxRange)
{
	float aveg = (float)arraySum(array, SIZE)/ SIZE;

	// the first element that surpases the average
	// for sure is grater that range + 1
	int lower = maxRange + 1;

	for (int i = 0; i < SIZE; i++) {
		if (array[i] > aveg && array[i] < lower)
			lower = array[i];
	}
	return lower;
}

void minMax(int array[], int SIZE, int *min, int *max)
{
	// Assume that the max and min is the fist element
	*min = array[0];
	*max = array[0];

	for (int i = 0; i < SIZE; i++) {
		if (array[i] < *min)
			*min = array[i];
		else if (array[i] > *max)
			*max = array[i];
	}
}

void minMaxMatrix(TMatrix m, int *min, int *max)
{
	*min = m[0][0];
	*max = m[0][0];

	for (int i = 0; i < KROWS; i++) {
		for (int j = 0; j < KCOLUMS; j++) {
			if (m[i][j] < *min)
				*min = m[i][j];
			else
				*max = m[i][j];
				
		}
	}
}

void sumColum(TMatrix m, TResult res)
{
	for (int colum = 0; colum < KCOLUMS; colum++) {
		res[colum] = 0;
		for (int row = 0; row < KROWS; row++) {
			res[colum] = m[row][colum];
		}
	}
}

// Fuctions for strings
void reverse(TString string)
{
	int i = 0, j, aux;
	j = strlen(string) - 1;

	while (i < j) {
		aux = string[i];
		string[i] = string[j];
		string[j] = aux;
		i++;
		j--;
	}
}

int main(void)
{


	return 0;
}
