/* Recursive program for Quick Sort */
#include <stdio.h>
#include <conio.h>
void quicksort(int, int);
int partition(int, int);
void interchange(int, int);
int array[25];
int main()
{
    int num, i = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    printf("Enter the elements: ");
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]);
    quicksort(0, num - 1);
    printf("\nThe elements after sorting are: ");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);
    return 0;
}
void quicksort(int low, int high)
{
    int pivotpos;
    if (low < high)
    {
        pivotpos = partition(low, high + 1);
        quicksort(low, pivotpos - 1);
        quicksort(pivotpos + 1, high);
    }
}
int partition(int low, int high)
{
    int pivot = array[low];
    int up = low, down = high;
    do
    {
        do
            up = up + 1;
        while (array[up] < pivot);
        do
            down = down - 1;
        while (array[down] > pivot);
        if (up < down)
            interchange(up, down);
    } while (up < down);
    array[low] = array[down];
    array[down] = pivot;
    return down;
}
void interchange(int i, int j)
{
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}