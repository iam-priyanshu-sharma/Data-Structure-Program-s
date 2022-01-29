/*Function to search an element from an array using advance sequential search*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void advseqsearch(int *,int,int);
void main()
    {
	    int a[MAX],n=0,ele,loc;
	    create(a,&n);
	    display(a,n);
	    printf("\nEnter element to serach:");
	    scanf("%d",&ele);
        loc=advseqsearch(a,n,ele);
	    if(loc==-1)
	        printf("\nElement not found in array.");
	    else
	        printf("\n%d found on %d.",ele,loc);
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
void advseqsearch(int *a,int n, int ele)
    {
        int i;
        for(i=0;i<n&&a[i]<=ele;i++)
            if(a[i]==ele)
                return i;
        return -1;
    }    