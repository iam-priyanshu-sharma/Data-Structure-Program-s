/*Function to search an element from an array using binary search technique (iterative)*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
int bsi(int *,int,int);
void main()
    {
	    int a[MAX],n=0,ele,loc;
	    create(a,&n);
	    display(a,n);
	    printf("\nEnter element to search:");
	    scanf("%d",&ele);
        loc=bsi(a,n,ele);
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
int bsi(int *a,int n, int ele)
    {
        int beg,mid,end;
        beg=0;
        end=n-1;
        while(beg<=end)
            {
                mid=(beg+end)/2;
                if(a[mid]==ele)
                    return mid;
                else if(a[mid]>ele)
                    end=mid-1;
                else
                    beg=mid+1;
            }
        return -1;
    }    