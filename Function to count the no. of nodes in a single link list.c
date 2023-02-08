/*Function to count the no. of nodes in a single link list*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
// void disp(node *);
void count(node *);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        // display(head);
        count(head);
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
/*void disp(node *h)
    {
        if(h==NULL)
            printf("\nList is empty.");
        else
            {
                printf("\nThe nodes of linked list in in-order are:");
                printf("\nAddress of Node\tInfo\tNext");
                while(h!=NULL)
                    {
                        printf("\n%u\t%d\t%u", h, h->info, h->next);
                        h = h->next;
                    }
            }
    }*/    
void count(node *h)
    {
        int count = 0;
        while(1)
            {
                if(h==NULL)
                    break;
                else
                    {
                        count++;
                        h = h->next;
                    }    
            }
            printf("\nNo. of nodes=%d", count);
    }    