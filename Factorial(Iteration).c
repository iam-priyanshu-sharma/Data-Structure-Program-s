#include <stdio.h>
#include <conio.h>
factorial(int);
main()
{
    int num, fact;
    printf("Enter a positive integer value: ");
    scanf("%d", &num);
    fact = factorial(num);
    printf("\n Factorial of %d =%5d\n", num, fact);
}
factorial(int n)
{
    int i, result = 1;
    if (n == 0)
        return (result);
    else
    {
        for (i = 1; i <= n; i++)
            result = result * i;
    }
    return (result);
}