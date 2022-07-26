/*A recursive function to compute the Fibonacci number in the nth position*/
#include <stdio.h>
#include <conio.h>
main()
{
    printf("fib(5) is % d", fib(5));
}
fib(n) int n;
{
    int x;
    if (n == 0 || n == 1)
        return n;
    x = fib(n - 1) + fib(n - 2);
    return (x);
}