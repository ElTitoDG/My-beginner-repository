#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{

    //Basic variables

    float valueOne, valueTwo, answer;
    char operator, selection;


    printf("Enter your operation: ");
    scanf("%f %c %f", &valueOne, &operator, &valueTwo);

    switch (operator)
    {
        case '/':
            answer = valueOne/valueTwo;
            break;
       case '*':
            answer = valueOne*valueTwo;
            break;
        case '+':
            answer = valueOne + valueTwo;
            break;
        case '-':
            answer = valueOne - valueTwo;
            break;
        case '^':
            answer = powf(valueOne, valueTwo);
            break;
        case 's':
            printf("Choose between this two options: ");
            printf("\t\t\ta. Value one\t\t\t");
            printf("\t\t\tb.Value two\t\t\t");
            scanf("%c", &selection);
            if(selection == 'a')
            {
                answer = sqrtf(valueOne);
            }
            else if(selection == 'b')
            {
                answer = sqrtf(valueTwo);
            }
            break;
        /* answer = valueOne/valueTwo; */
        /* break; */
        default:
            printf("fail\n");
    }

    printf("%.9g%c%.9g = %.9g\n\n", valueOne, operator, valueTwo, answer);

    return 0;
}
