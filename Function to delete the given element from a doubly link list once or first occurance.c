/*Function to delete the given element from a doubly link list(once/first occurance)*/
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
void delele(node **,node **);
void main()
    {
        node *head, *tail;
        head = tail = (node *)NULL;
        create(&head, &tail);
        disp(head);
        delele(&head,&tail);
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
void delele(node **h,node **t)
    {
        int ele;
        node *temp;
        if(*h==NULL)
            printf("\nList is empty.Deletion not possible.");
        else
            {
                printf("\nEnter element to be deleted:");
                scanf("%d", &ele);
                for (temp = *h; temp != NULL;temp=temp->next)
                    if(temp->info==ele)
                        break;
                if(temp==NULL)
                    printf("\nElement not found.Deletion not possible.");
                else
                    {
                        if(temp==*h)
                            if(*t==temp)
                                *h = *t = NULL;
                            else
                                {
                                    *h = temp->next;
                                    (*h)->prev = NULL;
                                }    
                        else
                            if(*t==temp)
                                {
                                    *t = temp->prev;
                                    (*t)->next = NULL;
                                }        
                            else
                                {
                                    (temp->next)->prev = temp->prev;
                                    (temp->prev)->next = temp->next;
                                }
                        free(temp);
                    }    
            }    
    }        