/* Program to calculate the least common multiple of a given number */
#include <stdio.h>
#include <conio.h>
int alone(int a[], int n);
long int lcm(int a[], int n, int prime);
void main()
{
    int a[20], status, i, n, prime;
    printf("Enter the limit:");
    scanf("% d", &n);
    printf("\nEnter the numbers:");
    for (i = 0; i < n; i++)
        scanf("% d", &a[i]);
    printf("\nThe least common multiple is % ld", lcm(a, n, 2));
}
int alone(int a[], int n)
{
    int k;
    for (k = 0; k < n; k++)
        if (a[k] != 1)
            return 0;
    return 1;
}
long int lcm(int a[], int n, int prime)
{
    int i, status;
    status = 0;
    if (alone(a, n))
        return 1;
    for (i = 0; i < n; i++)
        if ((a[i] % prime) == 0)
        {
            status = 1;
            a[i] = a[i] / prime;
        }
    if (status == 1)
        return (prime * lcm(a, n, prime));
    else
        return (lcm(a, n, prime = (prime == 2) ? prime + 1 : prime + 2));
}