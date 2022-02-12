/*Function to sort the elements of an array using modified bubble sort technique*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void modbubblesort(int *,int);
void main()
    {
    
	    int a[MAX],n=0,ele,loc;
	    create(a,&n);
	    display(a,n);
	    modbubblesort(a,n);
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
void modbubblesort(int *a,int n)
    {
        int i,j,temp,done=0;
        for(i=1;i<n && !done;i++)
            done=1;
            {
                for(j=0;j<n-i;j++)
                    if(a[j]>a[j+1])
                        {
                            done=0;
                            temp=a[j];
                            a[j]=a[j+1];
                            a[j+1]=temp;
                        }
            }
        printf("\nNo. of pass executed:%d",i-1);           
    }    