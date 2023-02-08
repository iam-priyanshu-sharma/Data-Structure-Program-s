/*Function to sort the elements of a single link list using bubble sort technique*/
#include<stdio.h>
#include<conio.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void display(node *);
void bubblesort(node *);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        display(head);
        bubblesort(head);
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
void bubblesort(node *h)
    {
        int temp;
        node *ptr,*ptr1,*loc=NULL;
        while(loc!=h)
            {
                for(ptr=h,ptr1=ptr->next;ptr1!=loc;ptr=ptr1,ptr1=ptr1->next)
                    {
                        if(ptr->info>ptr1->info)
                            {
                                temp=ptr->info;
                                ptr->info=ptr1->info;
                                ptr1->info=temp;
                            }
                    }
                loc=ptr;    
            }
    }