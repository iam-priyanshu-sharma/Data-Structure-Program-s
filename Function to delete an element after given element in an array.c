/*Function to delete an element after given element in an array*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void delaft(int *,int *);
void main()
    {
	    int a[MAX],n=0;
	    create(a,&n);
	    display(a,n);
	    delaft(a,&n);
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
void delaft(int *a,int *n)
    {
        int ele,i,j;
        if(*n==0)
            printf("\nList is empty,Deletion not possible.");
        else
            {
                printf("\nEnter element after which you want to delete:");
                scanf("%d",&ele);
                for(i=0;i<*n;i++)
                    if(a[i]==ele)
                        break;
                    if(*n==i)
                        printf("\nElement not found,Deletion not possible.");
                else if(i==(*n)-1)
                    printf("\nElement found at last position,Deletion not possible.");
                else
                    {
                        ele=a[i+1];
                        for(j=i+1;j<(*n)-1;j++)
                            a[j]=a[j+1];
                            (*n)--;
                        printf("\nDeleted element=%d",ele);
                    }
            }
    }    