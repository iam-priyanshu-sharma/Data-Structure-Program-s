/*Function to delete duplicate elements from a single link list*/
#include<stdio.h>
#include<conio.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void display(node *);
void deldup(node *);
void main()
    {
        node *head;
        head = ((node *)NULL);
        create(&head);
        display(head);
        deldup(head);
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
void deldup(node *h)
    {
        int count = 0;
        node *ptr, *ptr1, *pptr1, *temp;
        if(h==NULL)
            printf("\nList is empty.Deletion not possible.");
        else
            {
                for (ptr = h; ptr->next != NULL;ptr=ptr->next)
                    {
                        ptr1 = ptr->next;
                        pptr1 = ptr;
                        while(ptr1!=NULL)
                            if(ptr->info==ptr1->info)
                                {
                                    count++;
                                    temp = ptr1;
                                    ptr1 = ptr1->next;
                                    pptr1->next = ptr1;
                                    free(temp);
                                }
                            else
                                {
                                    pptr1 = ptr1;
                                    ptr1 = ptr1->next;
                                }    
                    }
                if(count==0)
                    printf("\nNo duplicate elements found.");
                else
                    printf("\n%d duplicate elements deleted.", count);
            }    
    }    