/*Function to sort the elements of an array using Quick sort technique*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void quicksort(int *,int,int);
int splitt(int *,int,int);
void main()
    {

        int a[MAX],n=0,ele,loc;
        create(a,&n);
        display(a,n);
        quicksort(a,0,n-1);
        printf("\nAfter sorting element of array are:");
        display(a,n);
        getch();
    }
void create(int *a,int *n)
    {
        int ele;
        while (1)
            {
                if(*n==MAX)
                    {
                        printf("\nArray is full,insertion not possible.");
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
            printf("\nList is empty.");
        else
            {
                printf("\nElement of array are:");
                printf("\nPosition	Element");
                for(i=0;i<n;i++)
                printf("\na[%d]\t\t=%d",i,a[i]);
            }
    }
void quicksort(int *a,int beg,int end)
	{
	    int loc;
	    if(beg<end)
	        {
	            loc=splitt(a,beg,end);
	            quicksort(a,beg,loc-1);
	            quicksort(a,loc+1,end);
	        }
	}
int splitt(int *a,int lt,int rt)
	{
	    int loc,temp,done=0;
	    loc=lt;
	    while(!done)
	        {
	            while(loc!=rt&&a[loc]<=a[rt])
	                rt--;
	            if(loc==rt)
	                done=1;
	            else
	                {
	                    temp=a[loc];
	                    a[loc]=a[rt];
	                    a[rt]=temp;
	                    loc=rt;
	                    lt++;
	                }
	            if(!done)
	                {
	                    while(loc!=lt&&a[loc]>=a[lt])
		                    lt++;
	                    if(loc==lt)
		                    done=1;
	                    else
		                    {
		                        temp=a[loc];
		                        a[loc]=a[lt];
		                        a[lt]=temp;
		                        loc=lt;
		                        rt--;
		                    }
	                }
	        }
	    return loc;
    }    