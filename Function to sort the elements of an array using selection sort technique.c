/*Function to sort the elements of an array using selection sort technique*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void selectionsort(int *,int);
void main()
    {
    
	    int a[MAX],n=0,ele,loc;
	    create(a,&n);
	    display(a,n);
	    selectionsort(a,n);
	    printf("\nAfter sorting element of array are:");
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
void selectionsort(int *a,int n)
    {
        int i,j,temp,s;
        for(i=0;i<n-1;i++)
            {
                s=i;
                for(j=i+1;j<n;j++)
                    if(a[s]>a[j])
                        s=j;
                    if(i!=s)
                        {
                            temp=a[i];
                            a[i]=a[s];
                            a[s]=temp;
                        } 
            }
        printf("\nNo. of pass executed:%d",i-1);    
    }    