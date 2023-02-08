/*Program to print sparce Matrix*/
#include<stdio.h>
#include<conio.h>
void input(int[][3]);
void disp(int[][3]);
void main()
    {
        int mat[10][3];
        printf("Enter no. of rows and columns of matrix:");
        scanf("%d%d", &mat[0][0], &mat[0][1]);
        printf("\nEnter no. of non-zero elements of sparce matrix:");
        scanf("%d", &mat[0][2]);
        input(mat);
        disp(mat);
        getch();
    }
void input(int a[][3])
    {
        int i;
        printf("\nEnter row no,col no. and value of non-zero elements:");
        for (i = 1; i <= a[0][2]; i++)
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }
void disp(int a[][3])
    {
        int i, j, k = 1;
        printf("\nThe Matrix is:\n");
        for (i = 0; i < a[0][0]; i++)
            {
                for (j = 0; j < a[0][1]; j++)
                    if(k<=a[0][2] && i==a[k][0] && j==a[k][1])
                        printf("\t%d", a[k++][2]);
                    else
                        printf("\t0");
                printf("\n");
            }
    }    