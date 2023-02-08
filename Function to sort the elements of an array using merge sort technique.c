/*Function to sort the elements of an array using merge sort technique*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void mergesort(int *,int,int);
void mergearr(int *,int,int,int,int);
void main()
    {

        int a[MAX],n=0,ele,loc;
        create(a,&n);
        display(a,n);
        mergesort(a,0,n-1);
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
void mergesort(int *a,int beg,int end)
	{
	    int mid;
	    if(beg<end)
	        {
	            mid=(beg+end)/2;
	            mergesort(a,beg,mid);
	            mergesort(a,mid+1,end);
	            mergearr(a,beg,mid,mid+1,end);
	        }
	}
void mergearr(int *a,int lb,int le,int rb,int re)
	{
	    int c[MAX],i,na,nb,nc;
	    na=nc=lb;
	    nb=rb;
	    while(na<=le&&nb<=re)
	        {
	            if(a[na]<a[nb])
	                c[nc++]=a[na++];
	            else
	                c[nc++]=a[nb++];
	        }
	    if(na>le)
	        while(nb<=re)
	            c[nc++]=a[nb++];
	    else
	        while(na<=le)
	            c[nc++]=a[na++];
	    for(i=lb;i<=re;i++)
	        a[i]=c[i];
    }    
