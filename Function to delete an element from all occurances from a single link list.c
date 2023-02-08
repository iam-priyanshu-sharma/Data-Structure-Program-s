/*Function to delete an element from all occurances from a single link list*/
#include<stdio.h>
#include<conio.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void display(node *);
void deleleall(node **);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        display(head);
        deleleall(&head);
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
void deleleall(node **h)
    {
        int ele, count = 0;
        node *loc, *ploc, *temp;
        if(*h==NULL)
            printf("\nlist is empty.Deletion not possible.");
        else
            {
                printf("\nEnter element you want to delete:");
                scanf("%d", &ele);
                loc = *h;
                while(loc!=NULL)
                    {
                        if(loc->info==ele)
                            {
                                temp = loc;
                                loc = loc->next;
                                if(*h==temp)
                                    *h = loc;
                                else
                                    ploc->next = loc;
                                count++;
                                free(temp);
                            }
                        else
                            {
                                ploc = loc;
                                loc = loc->next;
                            }    
                    }
                if(count==0)
                    printf("Element not found.Deletion not possible.");
                else
                    printf("\nElement deleted from %d positions", count);
            }    
    }    