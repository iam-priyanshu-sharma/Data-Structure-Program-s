/******************************************************************************

                        LINKED LIST OPERATIONS

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
    int info;
    struct nodes *next;
} node;

void create(node **);
void display(node *);
void disrev(node *);
void insbeg(node **);
void insend(node **);
void insaft(node *);
void insbef(node **);
void inssort(node **);





int main()
{
     node *head;
     head= ((node*)NULL);
     int ch;
     
    printf("\n enter command based on below menu (0 to end programme):\n");
    printf("\n1. To create a linked list\n2. To display a linked list\n3. To reverse a linked list\n4. To Insert element at beigning\n5. Insert element at end\n6. insert element after given element\n7. insert element before given element\n8. Inser element in sorted list\n");
    while(1){
        scanf("%d", &ch);
        
        if(ch==0){
            break;
        }else {
            
            switch(ch){
                case 1 : create(&head);
                break;
                case 2: display(head);
                         break;
                case 3: disrev(head);
                        break;
                case 4: insbeg(&head);
                        break;
                case 5: insend(&head);
                        break;
                case 6: insaft(head);
                        break;
                case 7: insbef(&head);
                        break;
                case 8: inssort(&head);
                        break;
                default : printf("you entered wrong choice!");
                break;
            }
        }
    }
}

void create(node **h){
    int ele;
    
    node *ptr, *last;
    
    printf("\nEnter elements in the node (-1 to exist) : ");
     
    while(1){
        scanf("%d", &ele);
        if(ele==-1){
                printf("\n enter command based on below menu (0 to end programme):\n");
                printf("\n1. To create a linked list\n2. To display a linked list\n3. To reverse a linked list\n4. To Insert element at beigning\n5. Insert element at end\n6. insert element after given element\n7. insert element before given element\n8. Inser element in sorted list\n");

            break;
        }
        else{
            ptr= (node *) malloc(sizeof(node));
            ptr->info=ele;
            ptr->next=NULL;
            
            if(*h==NULL){
                *h=last=ptr;
            }else{
                last=last->next=ptr;
            }
        }
    } 
}

void display(node *h){
    if(h==NULL){
        printf("\nList is empty\n");
    }else{
        while(h!=NULL){
            printf("%d\t",  h->info);
            h= h->next;
        }
    }
}

void disrev(node *h){
     if(h==NULL){
         printf("\nNodes elements of linked list are: \n");
     }else{
         disrev(h->next);
         printf("%d\t", h->info);
     }
 }


void insbeg(node **h){
    int ele;
    node *ptr;
    
    printf("\nEnter element you want to insert: ");
    scanf("%d", &ele);
    
    ptr= (node*)malloc(sizeof(node));
    ptr->info=ele;
    ptr->next= *h;
    *h=ptr;
}



void insend(node **h){
    int ele;
    
    node *ptr, *loc;
    
    printf("\nEnter element to inset at end of list: ");
    scanf("%d", &ele);
    ptr= (node*)malloc(sizeof(node));
    ptr->info=ele;
    ptr->next=NULL;
    
    if(*h==NULL){
        *h=ptr;
    }else{
        loc=*h;
        
        while(loc->next!=NULL){
            loc=loc->next;
        }
        
        loc->next=ptr;
    }
}


void insaft(node *h){
    int ele;
    node *ptr, *loc;
    ptr= (node*)malloc(sizeof(node));
    
    
    if(h==NULL){
        printf("\nList is empty insertion not possible.");
    }else{
         printf("\nEnter element after which you want to insert: ");
        scanf("%d", &ele);
        
        
    
    loc=h;
    
    while(loc!=NULL){
        if(loc->info==ele){
            break;
        }else{
            loc=loc->next;
        }
    }
    
    if(loc==NULL){
        printf("\nElements you search is not found.");
    }else{
        printf("\n Enter element to insert before given element: ");
        scanf("%d",&ele);
        ptr->info=ele;
        ptr->next=loc->next;
        loc->next=ptr;
        
    }
    
}
}

void insbef(node **h){
    int ele;
    node *ptr, *loc, *ploc;
    ptr=(node*)malloc(sizeof(node));
    
    if(*h==NULL){
        printf("\nList is empty");
    }else{
        
     
        printf("\nEnter element before you want to insert: ");
        scanf("%d", &ele);
        for(loc=*h; loc!=NULL; loc=loc->next){
            if(loc->info==ele){
                break;
            }else{
                ploc=loc;
            }
        }
        
        if(loc==NULL){
            printf("\nElement not found.");
        }else{
            printf("\nEnter element you want to insert before given element: ");
            scanf("%d", &ele);
            ptr->info=ele;
            ptr->next=loc;
            
            if(*h==loc){
                *h=ptr;
            }else{
                ploc->next=ptr;
            }
        }
    }
}



void inssort(node **h){
    int ele;
    node *ptr, *loc, *ploc;
    ptr=(node*)malloc(sizeof(node));
    
    printf("\nEnter element to insert in sorted list: ");
    scanf("%d", &ele);
    ptr->info=ele;
    
    
    for(loc=*h; loc!=NULL; loc=loc->next){
        if(loc->info>ele){
            break;
        }else{
            ploc=loc;
        }
    }
    ptr->next=loc;
    
    if(loc==*h){
        *h=ptr;
    }else{
        ploc->next=ptr;
    }
}
