#include <stdio.h>

int lsearch (int Arr[], int s, int item);

int main()
{
    int list[100], n, val, i;
    int found;

    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);

/*
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d : ", i + 1);
        scanf("&d", &list[i]);
    }
*/
    printf("\nEnter the number you want to search: ");
    scanf("%d", &val);

    found = lsearch(list, n, val);

    if (found)
    {
        printf("\nItem found");
    }
    else
    {
        printf("\nItem not found");
    }

    return 0;
}

int lsearch (int Arr[], int s, int item)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (Arr[i] == item)
        {
            return 1;
        }
    }
    return 0;
}
