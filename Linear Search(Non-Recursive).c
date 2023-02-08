/* A non-recursive program for Linear Search */
#include <stdio.h>
#include <conio.h>
main()
{
    int number[25], n, data, i, flag = 0;
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &number[i]);
    printf("\n Enter the element to be Searched: ");
    scanf("%d", &data);
    for (i = 0; i < n; i++)
    {
        if (number[i] == data)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("\n Data found at location: %d", i + 1);
    else
        printf("\n Data not found ");
}