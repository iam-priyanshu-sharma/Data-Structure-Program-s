/*Program to create a single linklist and display the elements in in-order and reverse order*/
#include<stdio.h>
#include<conio.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void disp(node *);
// void disp_rev(node *);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        disp(head);
        // disp_rev(head);
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
                if(ele==1)
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
void disp(node *h)
    {
        //node *ptr;
        if(h==NULL)
            printf("\nList is empty.");
        else
            {
                printf("\nThe nodes of linked list in in-order are:");
                printf("\nAddress of Node Info Next:");
                while(h!=NULL)
                    {
                        printf("\n%u\t%d\t%u", h, h->info, h->next);
                        h = h->next;
                    }
            }    
    }
/*void disp_rev(node *h)
    {
        if(head==NULL)
            {
                printf("\nList is empty.")
                return;
            }
        else    
            {
                if(h->next==NULL)
                    {
                        printf("%d", h->ele);
                        return;
                    }
                reverse(h->next);
                printf("%d", h->ele);
            }
    }*/
