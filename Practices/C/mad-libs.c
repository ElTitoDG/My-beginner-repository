#include <stdio.h>
#include <stdlib.h>

int main()
{

    char color[20], pluralNoun[20], celebrityF[20], celebrityL[20];

    printf("Enter a color: ");
    scanf("%s", color);
    printf("Enter a plural noun: ");
    scanf("%s", pluralNoun);
    printf("Enter a celebrity name: ");
    scanf("%s", celebrityF, celebrityL);

    printf("|-----------------------|\n");
    printf("|Roses are %s           |\n", color);
    printf("|%s are blue            |\n", pluralNoun);
    printf("|I love %s %s           |\n", celebrityF, celebrityL);
    printf("|-----------------------|\n");

    return 0;
}