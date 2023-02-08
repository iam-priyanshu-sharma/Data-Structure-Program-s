/*Program to create a single linklist and display the elements in in-order and reverse order*/
#include<stdio.h>
#include<conio.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void display(node *);
void display_reverse(node *);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        display(head);
        display_reverse(head);
        getch();
    }
void create(node **h)
    {
        int ele;
        node *ptr, *last;
        printf("Enter elements(-1 to exit):");
        while(1)
            {
                scanf("%d", &ele);
                if(ele==-1)
                    break;
                else
                    {
                        ptr = (node *)malloc(sizeof (node));
                        ptr->info = ele;
                        ptr->next = NULL;
                        if(*h==NULL)
                            *h = last = ptr;
                        else
                            last = last->next = ptr;
                    }    
            }
    }
void display(node *h)
    {
        node *ptr;
        if(h==NULL)
            printf("\nList is empty.");
        else
            {
                printf("\nThe nodes of linked list in in-order are:");
                printf("\nAddress of Node\tInfo\tNext:");
                while(h!=NULL)
                    {
                        printf("\n%u\t%d\t%u", h, h->info, h->next);
                        h = h->next;
                    }
            }    
    }
void display_reverse(node *h)
    {
        if(h==NULL)
            {
                printf("Nodes of Linked list in reverse order are:");
                printf("\nAddress of Node\tInfo\tNext");
            }
        else    
            {
                display_reverse(h->next);
                printf("\n%u\t%d\t%u", h, h->info, h->next);
            }    
    }
