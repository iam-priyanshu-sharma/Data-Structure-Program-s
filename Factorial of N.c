#include<stdio.h>
#include<conio.h>
int fact(int n)
    {
        if(n==0)
        return 1;
        return fact(n-1)*n;
    }
int Ifact(int n)  // Iterative
    {
        int f=1,i;
        for(i=1;i<=n;i++)
            f=f*i;
        return f;
    }
int main()
    {
        // int r = fact(6);
        int r=Ifact(5);
        printf("%d ",r);
        return 0;
    }