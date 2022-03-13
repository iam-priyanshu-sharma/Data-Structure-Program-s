/*Function to delete a given element in a single link list*/
#include<stdio.h>
#include<conio.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void display(node *);
void delele(node **);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        display(head);
        delele(&head);
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
                        ptr = (node *)malloc(sizeof(node));
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
                while(h!=NULL)
                    {
                        printf("\n%d",h->info);
                        h = h->next;
                    }
            }    
    }
void delele(node **h)
    {
        int ele;
        node *loc, *ploc;
        if(*h==NULL)
            printf("\nList is empty.Deletion not possible.");
        else
            {
                printf("\nEnter element you want to delete:");
                scanf("%d", &ele);
                for (loc = h; loc != NULL;loc=loc->next)
                    if(loc->info==ele)
                        break;
                    else
                        ploc = loc;
                if(loc==NULL)
                    printf("Element not found.Deletion not possible.");
                else
                    {
                        if(loc==*h)
                            *h = loc->next;
                        else
                            ploc->next = loc->next;
                        free(loc);
                    }    
            }    
    }    