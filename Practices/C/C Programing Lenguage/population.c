#include <stdlib.h>
#include <stdio.h>


int main(void) {

    int start_size = 0;
    int end_size = 0;
    int years = 0;

    do 
    {
        printf("Start Size: ");
        scanf("%i", &start_size);
    }
    while(start_size < 9);

    do
    {
        printf("End Size: ");
        scanf("%i", &end_size);
    }
    while(end_size < start_size);

    while (start_size < end_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }
    
    
    printf("\n");
    printf("Start Size: %i\n", start_size);
    printf("End Size: %i\n", end_size);
    printf("Years: %i\n", years);
    printf("\n");

}