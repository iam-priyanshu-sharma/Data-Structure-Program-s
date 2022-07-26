/* A Recursive program for linear search */
#include <stdio.h>
#include <conio.h>
void linear_search(int a[], int data, int position, int n)
{
    if (position < n)
    {
        if (a[position] == data)
            printf("\n Data Found at %d ", position);
        else
            linear_search(a, data, position + 1, n);
    }
    else
        printf("\n Data not found");
}
void main()
{
    int a[25], i, n, data;
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n Enter the element to be seached: ");
    scanf("%d", &data);
    linear_search(a, data, 0, n);
    getch();
}