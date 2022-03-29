/*Function to insert element before given element in a doubly link list*/
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
void insbef(node **);
void main()
    {
        node *head, *tail;
        head = tail = (node *)NULL;
        create(&head, &tail);
        disp(head);
        insbef(&head);
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
void insbef(node **h)
    {
        int ele;
        node *ptr, *loc;
        if(h==NULL)
            printf("\nList is empty.Insetion not possible.");
        else
            {
                printf("\nEnter element before which you want to insert:");
                scanf("%d", &ele);
                for (loc = h; loc != NULL;loc=loc->next)
                    if(loc->info==ele)
                        break;
                if(loc==NULL)
                    printf("\nElement not found.Insertion not possible.");
                else
                    {
                        printf("\nEnter element to be inserted:");
                        scanf("%d", &ele);
                        ptr = (node *)malloc(sizeof(node));
                        ptr->info = ele;
                        ptr->next = loc;
                        ptr->prev = loc->prev;
                        if(*h==loc)
                            *h = ptr;
                        else
                            (loc->prev)->next = ptr;
                        loc->prev = ptr;
                    }    
            }    
    }    