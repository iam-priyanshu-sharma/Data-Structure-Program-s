/*Function to insert an element after given element is an array*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create(int *,int *);
void display(int *,int);
void insaft(int *,int *);
void main()
    {
	    int a[MAX],n=0;
	    create(a,&n);
	    display(a,n);
	    insaft(a,&n);
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
void insaft(int *a,int *n)
    {
        int ele,i,pos;
        if(*n==MAX)
            printf("\nList is full,Insertion not possible.");
        else
            {
                printf("\nEnter element after which you want to insert:"); 
                scanf("%d",&ele);
                for(pos=0;pos<*n;pos++)
                    if(a[pos]==ele)
                        break;
                    if(pos==*n)
                        printf("\nElement not found.");
                    else
                        {
                            printf("\nEnter element to be inserted:");
                            scanf("%d",&ele);
                            for(i=*n;i>pos+1;i--)
                                a[i]=a[i-1];
                                a[i]=ele;
                                (*n)++;
                        }
            }
    }   