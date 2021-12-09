#include<stdlib.h>
#include<stdio.h>
/*
    Test numbers: 
        5555555555554444, 
        5105105105105100, 
        4012888888881881,
*/


int main(void)
{
    printf("\n");
    printf("Welcome to the credit card validator\n");
    
    //Get Card number || Isn't working IDK why
    long long int card;
    do
    {
        card = printf("Card Number: "); 
        scanf("%l64d", &card);
    }
    while (card > 0);
    printf("\n");
    //Count leght of the card
    int count = 0;
    long card_no = card;
    while (card_no > 0)
    {
        card_no = card_no / 10;
        count++;
    }

    //Check leght of the card
    if (count != 13 || count != 15 || count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    //Calculate checksum
    int sum1 = 0, sum2 = 0;
    long x = card;
    int total = 0, mod1, mod2, d1, d2;

    do
    {
        //Remove last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;

        //Remove second last digit
        mod2 = x % 10;
        x = x / 10;

        //Double second last digit and addded to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);

    total = sum1 + sum2;

    //Check Luhn algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Starting digits
    long start = card;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    //Check starting digits for model
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("Card model: MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("Card model: AMERICAN EXPRESS\n");
    }
    else if (start / 10 == 4)
    {
        printf("Card model: VISA\n");
    }
    else
    {
        printf("Card model: INVALID\n");
    }

    printf("\n");
}