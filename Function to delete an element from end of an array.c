/*Function to delete an element from end of an array*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void delend(int *,int *);
void main()
    {
	    int a[MAX],n=0;
	    create(a,&n);
	    display(a,n);
	    delend(a,&n);
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
	                    printf("Array is full,insertion not possible.");
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
            printf("\nArray is empty.");
        else
            {
                printf("\nElement of array are:-");
                printf("\nPosition 	  element");
                for(i=0;i<n;i++)
                    printf("\na[%d]\t\t=%d",i,a[i]);
            }
    }
void delend(int *a,int *n)
    {
        int ele;
        if(*n==0)
            printf("\nList is empty,Deletion not possible.");
        else
            {
                ele=a[(*n)-1];
                (*n)--;
                printf("\nDeleted Element=%d",ele);
            }
    }    