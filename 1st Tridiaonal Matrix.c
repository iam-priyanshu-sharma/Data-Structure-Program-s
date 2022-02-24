/*Program to print 1st tridiagonal matrix*/
#include<stdio.h>
#include<conio.h>
void input(int [][10], int);
void disp(int [][10], int);
void main()
    {
        int mat[10][10], r;
        printf("Enter row/column of matrix:");
        scanf("%d", &r);
        input(mat, r);
        disp(mat, r);
        getch();
    }
void input(int a[][10],int r)
    {
        int i, j;
        printf("\nEnter diagonal(non-zero)elements:");
        for (i = 0; i < r;i++)
            for (j = 0; j < r;j++)
                if(i==j || i+1==j || i-1 == j)
                    scanf("%d", &a[i][j]);
                else
                    a[i][j] = 0;
    }    
void disp(int a[][10],int r)
    {
        int i, j;
        printf("The matrix is:\n");
        for (i = 0; i < r; i++)
            {
                for (j = 0; j < r; j++)
                    printf("\t%d", a[i][j]);
                printf("\n");
            }
    }            