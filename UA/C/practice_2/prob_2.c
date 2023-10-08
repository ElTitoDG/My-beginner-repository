#include <stdio.h>
#include <math.h> // -lm compiler flag

int main()
{

    int fuel;
    float con, autonomy;

    printf("Welcome to the autonomy car calculator (ACC)\n");
    printf("Please introduce your current gas deposit and the average consumption: ");
    scanf("%i %f", &fuel, &con);

    printf("Your current fuel is %i and the consumtion is %.2f\n", fuel, con);

    autonomy = (fuel/(con/100));

    printf("Autonomy: %.2f\n", autonomy);

    return 0;
}
