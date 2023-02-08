/*Function to insert an element at the given position in an array*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void inspos(int *,int *);
void main()
    {
	    int a[MAX],n=0;
	    create(a,&n);
	    display(a,n);
	    inspos(a,&n);
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
void inspos(int *a,int *n)
    {
        int i,ele,pos;
        if(*n==MAX)
            printf("\nArray is full,Insertion not possible.");
        else
            {
                printf("\nEnter position where you want to insert:");
                scanf("%d",&pos);
                if(pos<0||pos>*n)
                    printf("\nInvalid position value,Insertion not possible.");
                else
                    {
                        printf("\nEnter element to be inserted:");
                        scanf("%d",&ele);
                        for(i=*n;i>pos;i--)
                            a[i]=a[i-1];
                            a[pos]=ele;
                            (*n)++;
                    }
            }
    }     