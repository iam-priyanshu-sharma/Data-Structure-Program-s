/*Function to merge the elements of a single linked list*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void disp(node *);
void merge(node **, node **, node **);
void main()
    {
        node *head1, *head2, *head3;
        head1 = head2 = head3 = NULL;
        printf("\nCreate 1st linked list.");
        create(&head1);
        printf("\nCreate 2nd linked list.");
        create(&head2);
        printf("\nThe 1st list is:");
        disp(head1);
        printf("\nThe 2nd list is:");
        disp(head2);
        merge(&head1, &head2, &head3);
        printf("\nThe resultant list is:");
        disp(head3);
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
void disp(node *h)
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
    }
void merge(node **h1,node **h2,node **h3)
    {
        node *ptr, *last;
        if(*h1==NULL && *h2==NULL)
            printf("\nBoth lists are empty.");
        else if(*h1==NULL)
            *h3 = *h2;
        else if(*h2==NULL)
            *h3 = *h1;
        else
            {
                while(*h1!=NULL && *h2!=NULL)
                    {
                        if((*h1)->info<(*h2)->info)
                            {
                                ptr = *h1;
                                *h1 = (*h1)->next;
                            }
                        else
                            {
                                ptr = *h2;
                                *h2 = (*h2)->next;
                            }
                        if(*h3==NULL)
                            *h3 = last = ptr;
                        else
                            last = last->next = ptr;
                    }
                if(*h1==NULL)
                    last->next = *h2;
                else
                    last->next = *h1;
                *h1 = *h2 = NULL;
            }    
    }
