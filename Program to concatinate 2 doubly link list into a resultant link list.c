/*Program to concatinate 2 doubly link list into a resultant link list*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodes
    {
        int info;
        struct nodes *prev, *next;
    } node;
void create(node **, node **);
void disp(node *);
void concat(node **, node **, node **, node **, node **, node **);
void main()
    {
        node *head1, *tail1, *head2, *tail2, *head3, *tail3;
        head1 = tail1 = head2 = tail2 = head3 = tail3 = (node *)NULL;
        printf("Create 1st list:");
        create(&head1, &tail1);
        printf("Create 2nd list:");
        create(&head2, &tail2);
        printf("\n1st list is:");
        disp(head1);
        printf("\n2nd list is:");
        disp(head2);
        concat(&head1, &tail1, &head2, &tail2, &head3, &tail3);
        printf("\nThe Resultant list is:");
        disp(head3);
        getch();
    }
void create(node **h,node **t)
    {
        int ele;
        node *ptr;
        while(1)
            {
                printf("\nEnter number(-1 to exit):");
                scanf("%d", &ele);
                if(ele==-1)
                    break;
                else
                    {
                        ptr = (node *)malloc(sizeof(node));
                        ptr->next = ptr->prev = NULL;
                        ptr->info = ele;
                        if(*h==NULL)
                            *h = *t = ptr;
                        else
                            {
                                (*t)->next = ptr;
                                ptr->prev = *t;
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
                printf("\nThe list in in-order is:");
                printf("\nAddress od node\tPrev\tInfo\tNext");
                while(h!=NULL)
                    {
                        printf("\n%u\t%u\t%d\t%u", h, h->prev, h->info, h->next);
                        h = h->next;
                    }
            }    
    }    
void concat(node **h1,node **t1,node **h2,node **t2,node **h3,node **t3)
    {
        if(*h1==NULL && *h2==NULL)
            printf("\nBoth lists are empty.");
        else if(*h1==NULL)
            {
                *h3 = *h2;
                *t3 = *t2;
            }    
        else if(*h2==NULL)
            {
                *h3 = *h1;
                *t3 = *t1;
            }
        else
            {
                *h3 = *h1;
                (*t1)->next = *h2;
                (*h2)->prev = *t1;
                *t3 = *t2;
            }
        *h1 = *h2 = *t1 = *t3 = NULL;
    }    