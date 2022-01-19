/*Program to create an array for 10 elements, insert some elements in the array and display the
elements in in-order and reverse order*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int );
void disp_rev(int *,int );
void main()
    {
        int a[MAX],n=0;
        create(a,&n);
        display(a,n);
        disp_rev(a,n);
        getch();
    }
void create(int *a,int *n)
    {
        int ele;
        printf("Enter elements(-1 to exit):");
        while(1)
            {
                if(*n==MAX)
                    {
                        printf("\nSorry…… Array is full.");
                        break;
                    }
                scanf("%d",&ele);
                if(ele==-1)
                    break;
                else
                    a[(*n)++]=ele;
            }
    }
void display(int *a,int n)
    {
        int i;
        if(n==0)
            printf("\nArray is empty.");
        else
            {
                printf("\nElements of array are:");
                printf("\nPosition Element.");
                for(i=0;i<n;i++)
                    printf("\na[%d]=\t\t%d",i,a[i]);
            }
    }
void disp_rev(int *a,int n)
    {
        int i;
        system("cls");
        if(n==0)
            printf("\nArray is empty.");
        else
            {
                printf("\nElements of array in reverse order are:");
                printf("\nPosition Element.");
                for(i=n-1;i>=0;i--)
                    printf("\na[%d]=\t%d",i,a[i]);
            }
    }
