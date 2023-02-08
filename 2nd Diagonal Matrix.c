/*Program to print 2nd diagonal matrix*/
#include<stdio.h>
#include<conio.h>
void input(int *, int);
void disp(int *, int);
void main()
    {
        int mat[10], r;
        printf("Enter row/column of matrix:");
        scanf("%d", &r);
        input(mat, r);
        disp(mat, r);
        getch();
    }
void input(int *a,int r)
    {
        int i;
        printf("\nEnter diagonal(non-zero)elements:");
        for (i = 0; i < r;i++)
            scanf("%d", &a[i]);
    }
void disp(int *a,int r)
    {
        int i, j;
        printf("\nThe Matrix is:\n");
        for (i = 0; i < r;i++)
            {
                for (j = 0; j < r;j++)
                    if(i+j==r-1)
                        printf("\t%d", a[i]);
                    else
                        printf("\t0");
                printf("\n");
            }
    }