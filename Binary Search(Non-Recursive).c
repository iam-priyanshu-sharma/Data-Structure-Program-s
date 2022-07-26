/* A non-recursive program for binary search */
#include <stdio.h>
#include <conio.h>
main()
{
    int number[25], n, data, i, flag = 0, low, high, mid;
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n Enter the elements in ascending order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &number[i]);
    printf("\n Enter the element to be searched: ");
    scanf("%d", &data);
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (number[mid] == data)
        {
            flag = 1;
            break;
        }
        else
        {
            if (data < number[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    if (flag == 1)
        printf("\n Data found at location: %d", mid + 1);
    else
        printf("\nData Not Found ");
}