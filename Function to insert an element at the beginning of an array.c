/*Function to insert an element at the beginning of an array*/ 
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void insbeg(int *,int *);
void main()
    {
	    int a[MAX],n=0;
        system("cls");
        create(a,&n);
        display(a,n);
        insbeg(a,&n);
        display(a,n);
        getch();
    }
void create(int *a,int *n)
    {
	    int ele;
	    while(1)
	        {
	            if(*n==MAX)
	                {
	                    printf("\nArray is full.Insertion not possible.");
	                    break;
	                }
	            else
	                {
	                    printf("\nEnter elements(-1 to exit):");
	                    scanf("%d",&ele);
	                    if(ele==-1)
	                        break;
	                    else
	                        a[(*n)++]=ele;
	                }
            }
    }
void display(int *a,int n)
    {
        int i;
        if(n==0)
            printf("\nArray is empty");
        else
            {
                printf("\nelement of array are:-");
                printf("\nposition	 element");
                for(i=0;i<n;i++)
                    printf("\na[%d]\t\t=%d",i,a[i]);
            }
    }
void insbeg(int *a,int *n)
    {
	    int i,ele;
	    if(*n==MAX)
	        printf("\narray is full,insertion not possible");
     	else
	        {
	            printf("\nEnter element to be inserted at beginning");
	            scanf("%d",&ele);
	            for(i=*n;i>0;i--)
	                a[i]=a[i-1];
	                a[0]=ele;
	                (*n)++;
	        }
    }

