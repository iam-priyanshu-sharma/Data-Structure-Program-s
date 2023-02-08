#include <stdio.h>
#include <conio.h>
int factorial(int);
main()
{
    int num, fact;
    printf("Enter a positive integer value: ");
    scanf("%d", &num);
    fact = factorial(num);
    printf("\n Factorial of %d =%5d\n", num, fact);
}
int factorial(int n)
{
    int result;
    if (n == 0)
        return (1);
    else
        result = n * factorial(n - 1);
    return (result);
}