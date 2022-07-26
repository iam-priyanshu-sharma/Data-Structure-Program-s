/* Program to calculate the greatest common divisor */
#include <stdio.h>
#include <conio.h>
int check_limit(int a[], int n, int prime);
int check_all(int a[], int n, int prime);
long int gcd(int a[], int n, int prime);
void main()
{
    int a[20], stat, i, n, prime;
    printf("Enter the limit:");
    scanf("%d", &n);
    printf("\nEnter the numbers:");
    for (i = 0; i < n; i++)
        scanf("\n%d", &a[i]);
    printf("\nThe greatest common divisor is %ld", gcd(a, n, 2));
}
int check_limit(int a[], int n, int prime)
{
    int i;
    for (i = 0; i < n; i++)
        if (prime > a[i])
            return 1;
    return 0;
}
int check_all(int a[], int n, int prime)
{
    int i;
    for (i = 0; i < n; i++)
        if ((a[i] % prime) != 0)
            return 0;
    for (i = 0; i < n; i++)
        a[i] = a[i] / prime;
    return 1;
}
long int gcd(int a[], int n, int prime)
{
    int i;
    if (check_limit(a, n, prime))
        return 1;
    if (check_all(a, n, prime))
        return (prime * gcd(a, n, prime));
    else
        return (gcd(a, n, prime = (prime == 2) ? prime + 1 : prime + 2));
}