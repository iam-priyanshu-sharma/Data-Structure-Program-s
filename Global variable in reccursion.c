#include<stdio.h>
#include<conio.h>
int x=0;
int fun(int n)
    {
        if(n>0)
            {
                x++;
                return fun(n-1)+x;
            }
        return 0;
    }
int main()
    {
        int r;
        r=fun(5);
        printf("%d\n",r);
        r=fun(5);
        printf("%d\n",r);
        return 0;
    }    