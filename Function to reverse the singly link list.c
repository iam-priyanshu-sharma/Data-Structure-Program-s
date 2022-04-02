/*Function to reverse the singly link list*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void reverse(node *);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        reverse(head);
        getch();
    
    }
void create(node **h)
    {
        int ele;
        node *ptr, *last;
        while(1)
            {
                printf("\nEnter elements(-1 to exit):");
                scanf("%d", &ele);
                if(ele==-1)
                    break;
                else
                    {
                        ptr = (node *)malloc(sizeof(node));
                        ptr->next = (node *)NULL;
                        ptr->info = ele;
                        if(*h==NULL)
                            *h = last = ptr;
                        else
                            last = last->next = ptr;
                    }    
            }
    } 
void reverse(node *h)
    {
        node *pre,*curr,*next;
        pre=0;
        curr=next=h;
        while(next!=0)
            {
                next=next->next;
                curr->next=pre;
                pre=curr;
                curr = next;
            }
        h=pre;    
    }
