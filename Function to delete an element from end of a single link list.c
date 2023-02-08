/*Function to delete an element from end of a single link list*/
#include<stdio.h>
#include<conio.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void display(node *);
void delend(node **);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        display(head);
        delend(&head);
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
void delend(node **h)
    {
        int ele;
        node *temp, *ptemp;
        if(*h==NULL)
            printf("\nList is empty.Deletion not possible.");
        else
            {
                for (temp = *h, temp->next != NULL; temp = temp->next; ptemp = temp)
                    if(*h==temp)
                        *h = NULL;
                    else
                        ptemp->next = NULL;
                ele = temp->info;
                free(temp);
                printf("\nDeleted elements=%d", ele);                 
            }
    }    