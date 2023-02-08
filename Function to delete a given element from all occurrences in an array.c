/*Function to delete a given element from all occurrences in an array*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void deleleall(int *,int *);
void main()
    {
	    int a[MAX],n=0;
	    create(a,&n);
	    display(a,n);
	    deleleall(a,&n);
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
void deleleall(int *a,int *n)
    {
        int ele,i,j,count=0;
        if(*n==0)
            printf("\nList is empty,Deletion not possible.");
        else
            {
                printf("\nEnter element to be deleted:");
                scanf("%d",&ele);
                i=0;
                while(i<*n)
                    {
                        if(a[i]==ele)
                            {
                                count++;
                                for(j=i;j<(*n)-1;j++)
                                    a[j]=a[j+1];
                                (*n)--;
                            }
                        else
                            i++;
                    }
                if(count==0)
                    printf("\nElement not found.");
                else
                    printf("\nElement deleted from %d positions.",count);
            }
    }    