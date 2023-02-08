/*Function to delete all duplicate elements from an array*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void deldup(int *,int *);
void main()
    {
	    int a[MAX],n=0;
	    create(a,&n);
	    display(a,n);
	    deldup(a,&n);
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
void deldup(int *a,int *n)
    {
        int i,j,k,count=0;
        if(*n==0)
            printf("\nList is empty,Deletion not possible.");
        else
            {
                for(i=0;i<(*n)-1;i++)
                    {
                        j=i+1;
                        while(j<*n)
                            if(a[i]==a[j])
                                {
                                    count++;
                                    for(k=j;k<(*n)-1;k++)
                                        a[k]=a[k+1];
                                        (*n)--;
                                }
                            else
                                j++;
                    }
                if(count==0)
                    printf("\nNo duplicate element found.");
                else
                    printf("\n%d duplicate element deleted.",count);
            }
    }    