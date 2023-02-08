/*Function to delete an element from given position in an array*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void delpos(int *,int *);
void main()
    {
	    int a[MAX],n=0;
	    create(a,&n);
	    display(a,n);
	    delpos(a,&n);
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
void delpos(int *a,int *n)
    {
        int ele,i,pos;
        if(*n==0)
            printf("\nList is empty,Deletion not possible.");
        else
            {
                printf("\nEnter position from where you want to delete:");
                scanf("%d",&pos);
                if(pos<0||pos>(*n)-1)
                    printf("\nInvalid position value.");
                else
                    {
                        ele=a[pos];
                        for(i=pos;i<(*n)-1;i++)
                            a[i]=a[i+1];
                            (*n)--;
                        printf("\nDeleted element=%d",ele);
                    }
            }
    }    