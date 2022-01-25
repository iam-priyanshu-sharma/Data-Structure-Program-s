/*Function to search an element from an array using binary search technique(recursive)*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void bsr(int *,int,int,int);
void main()
    {
	    int a[MAX],n=0,ele,loc;
	    create(a,&n);
	    display(a,n);
	    printf("\nEnter element to serach:");
	    scanf("%d",&ele);
        loc=bsr(a,0,n-1,ele);
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
void bsr(int *a,int beg,int end,int ele)
	{
	    int mid;
   	    if(beg<=end)
	        {
	            mid=(beg+end)/2;
	            if(a[mid]==ele)
	                return mid;
	            else if(a[mid]>ele)
	                return(bsr(a,beg,mid-1,ele));
	            else
	                return(bsr(a,mid+1,end,ele));
	        }
	    return -1;
	}     
             
        