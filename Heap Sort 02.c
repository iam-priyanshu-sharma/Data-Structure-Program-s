/* Program for Heap Sort */
void adjust(int i, int n, int a[])
{
    int j, item;
    j = 2 * i;
    item = a[i];
    while (j <= n)
    {
        if ((j < n) && (a[j] < a[j + 1]))
            j++;
        if (item >= a[j])
            break;
        else
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = item;
}
void heapify(int n, int a[])
{
    int i;
    for (i = n / 2; i > 0; i--)
        adjust(i, n, a);
}
void heapsort(int n, int a[])
{
    int temp, i;
    heapify(n, a);
    for (i = n; i > 0; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        adjust(1, i - 1, a);
    }
}
void main()
{
    int i, n, a[20];
    printf("\n How many element you want: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    heapsort(n, a);
    printf("\n The sorted elements are: \n");
    for (i = 1; i <= n; i++)
        printf("%5d", a[i]);
    getch();
}