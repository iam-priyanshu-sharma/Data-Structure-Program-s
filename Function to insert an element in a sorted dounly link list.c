/*Function to insert an element in a sorted doubly link list*/
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
void inssorted(node **, node **);
void main()
    {
        node *head, *tail;
        head = tail = (node *)NULL;
        create(&head, &tail);
        disp(head);
        inssorted(&head,&tail);
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
void inssorted(node **h,node **t)
    {
        int ele;
        node *ptr, *loc;
        printf("\nEnter element to be inserted:");
        scanf("%d", &ele);
        ptr = (node *)malloc(sizeof(node));
        ptr->info = ele;
        for (loc = *h; loc != NULL;loc=loc->next)
            if(loc->info>ele)
                break;
        ptr->next = loc;
        if(loc==NULL)
            {
                if(&h==NULL)
                    {
                        *h = *t = ptr;
                        ptr->prev = NULL;
                    }
                else
                    {
                        (*t)->next = ptr;
                        ptr->prev = *t;
                        *t = ptr;
                    }    
            }
        else
            {
                if(*h==loc)
                    {
                        ptr->prev = NULL;
                        (*h)->prev = ptr;
                        *h = ptr;
                    }
                else
                    {
                        ptr->prev = loc->prev;
                        (loc->prev)->next = ptr;
                        loc->prev = ptr;
                    }    
            }    
    }