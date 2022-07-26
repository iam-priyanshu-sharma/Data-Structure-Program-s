/* A recursive program for binary search */
#include <stdio.h>
#include <conio.h>
void bin_search(int a[], int data, int low, int high)
{
    int mid;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == data)
            printf("\n Element found at location: %d ", mid + 1);
        else
        {
            if (data < a[mid])
                bin_search(a, data, low, mid - 1);
            else
                bin_search(a, data, mid + 1, high);
        }
    }
    else
        printf("\n Element not found");
}
void main()
{
    int a[25], i, n, data;
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n Enter the elements in ascending order: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\n Enter the element to be searched: ");
    scanf("%d", &data);
    bin_search(a, data, 0, n - 1);
    getch();
}