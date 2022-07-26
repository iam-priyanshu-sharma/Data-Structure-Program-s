/* Recursive Program for selection sort */
#include <stdio.h>
#include <conio.h>
int x[6] = {77, 33, 44, 11, 66};
selectionSort(int);
main()
{
    int i, n = 0;
    printf(" Array Elements before sorting: ");
    for (i = 0; i < 5; i++)
        printf("%d ", x[i]);
    selectionSort(n); /* call selection sort */
    printf("\n Array Elements after sorting: ");
    for (i = 0; i < 5; i++)
        printf("%d ", x[i]);
}
selectionSort(int n)
{
    int k, p, temp, min;
    if (n == 4)
        return (-1);
    min = x[n];
    p = n;
    for (k = n + 1; k < 5; k++)
    {
        if (x[k] < min)
        {
            min = x[k];
            p = k;
        }
    }
    temp = x[n]; /* interchange x[n] and x[p] */
    x[n] = x[p];
    x[p] = temp;
    n++;
    selectionSort(n);
}