/*Function to search an element in a single link list*/
#include<stdio.h>
#include<conio.h>
typedef struct nodes
    {
        int info;
        struct nodes *next;
    } node;
void create(node **);
void display(node *);
node *search(node *, int);
void main()
    {
        node *loc,*head;
        int ele;
        head = ((node *)NULL);
        create(&head);
        display(head);
        printf("\nEnter element you want to search:");
        scanf("%d", &ele);
        loc = search(head, ele);
        if(loc==NULL)
            printf("\nElement not found.");
        else
            printf("\nElement found at %u location", loc);
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
node *search(node *h,int ele)
    {
        while(h!=NULL)
            if(h->info==ele)
                return h;
            else
                h = h->next;
        return NULL;
    }    