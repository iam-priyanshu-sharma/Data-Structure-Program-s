/*Function to delete the last element of a doubly link list*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodes
    {
        int info;
        struct nodes *next, *prev;
    } node;
void create(node **, node **);
void disp(node *);
void delend(node **,node **);
void main()
    {
        node *head, *tail;
        head = tail = (node *)NULL;
        create(&head, &tail);
        disp(head);
        delend(&head,&tail);
        getch();
    }
void create(node **h,node **t)
    {
        int ele;
        node *ptr;
        while(1)
            {
                printf("\nEnter elements(-1 to exit):");
                scanf("%d", &ele);
                if(ele==-1)
                    break;
                else
                    {
                        ptr = (node *)malloc(sizeof(node));
                        ptr->info = ele;
                        ptr->next = NULL;
                        ptr->prev = *t;
                        if(*h==NULL)
                            *h = *t = ptr;
                        else
                            {
                                (*t)->next = ptr;
                                *t = ptr;
                            }    
                    }    
            }
    }    
void disp(node *h)
    {
        if(h==NULL)
            printf("\nList is empty.");
        else
            {
                printf("\nNodes of linked list are:");
                printf("\nAddress of Node\tPrev\t\tInfo\tNext");
                while(h!=NULL)
                    {
                        printf("\n%u\t%u\t%d\t%u", h, h->prev, h->info, h->next);
                        h = h->next;
                    }
            }    
    }
void delend(node **h,node **t)
    {
        int ele;
        node *temp;
        if(*h==NULL)
            printf("\nList is empty.Deletion not possible.");
        else
            {
                temp = *t;
                *t = (*t)->prev;
                if(*t==NULL)
                    *h = NULL;
                else
                    (*t)->next = NULL;
                ele = temp->info;
                free(temp);
                printf("\nDeleted element=%d",ele);
            }    
    }    