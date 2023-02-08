/* Source Code for Circular Double Linked List */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct cdlinklist
{
    struct cdlinklist *left;
    int data;
    struct cdlinklist *right;
};
typedef struct cdlinklist node;
node *start = NULL;
int nodectr;
node *getnode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int menu()
{
    int ch;
    printf("\n 1. Create ");
    printf("\n\n--------------------------");
    printf("\n 2. Insert a node at Beginning");
    printf("\n 3. Insert a node at End");
    printf("\n 4. Insert a node at Middle");
    printf("\n\n--------------------------");
    printf("\n 5. Delete a node from Beginning");
    printf("\n 6. Delete a node from End");
    printf("\n 7. Delete a node from Middle");
    printf("\n\n--------------------------");
    printf("\n 8. Display the list from Left to Right");
    printf("\n 9. Display the list from Right to Left");
    printf("\n 10.Exit");
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}
void cdll_createlist(int n)
{
    int i;
    node *newnode, *temp;
    if (start == NULL)
    {
        nodectr = n;
        for (i = 0; i < n; i++)
        {
            newnode = getnode();
            if (start == NULL)
            {
                start = newnode;
                newnode->left = start;
                newnode->right = start;
            }
            else
            {
                newnode->left = start->left;
                newnode->right = start;
                start->left->right = newnode;
                start->left = newnode;
            }
        }
    }
    else
        printf("\n List already exists..");
}
void cdll_display_left_right()
{
    node *temp;
    temp = start;
    if (start == NULL)
        printf("\n Empty List");
    else
    {
        printf("\n The contents of List: ");
        printf(" %d ", temp->data);
        temp = temp->right;
        while (temp != start)
        {
            printf(" %d ", temp->data);
            temp = temp->right;
        }
    }
}
void cdll_display_right_left()
{
    node *temp;
    temp = start;
    if (start == NULL)
        printf("\n Empty List");
    else
    {
        printf("\n The contents of List: ");
        do
        {
            temp = temp->left;
            printf("\t%d", temp->data);
        } while (temp != start);
    }
}
void cdll_insert_beg()
{
    node *newnode;
    newnode = getnode();
    nodectr++;
    if (start == NULL)
    {
        start = newnode;
        newnode->left = start;
        newnode->right = start;
    }
    else
    {
        newnode->left = start->left;
        newnode->right = start;
        start->left->right = newnode;
        start->left = newnode;
        start = newnode;
    }
}
void cdll_insert_end()
{
    node *newnode, *temp;
    newnode = getnode();
    nodectr++;
    if (start == NULL)
    {
        start = newnode;
        newnode->left = start;
        newnode->right = start;
    }
    else
    {
        newnode->left = start->left;
        newnode->right = start;
        start->left->right = newnode;
        start->left = newnode;
    }
    printf("\n Node Inserted at End");
}
void cdll_insert_mid()
{
    node *newnode, *temp, *prev;
    int pos, ctr = 1;
    newnode = getnode();
    printf("\n Enter the position: ");
    scanf("%d", &pos);
    if (pos - nodectr >= 2)
    {
        printf("\n Position is out of range..");
        return;
    }
    if (pos > 1 && pos <= nodectr)
    {
        temp = start;
        while (ctr < pos - 1)
        {
            temp = temp->right;
            ctr++;
        }
        newnode->left = temp;
        newnode->right = temp->right;
        temp->right->left = newnode;
        temp->right = newnode;
        nodectr++;
        printf("\n Node Inserted at Middle.. ");
    }
    else
        printf("position %d of list is not a middle position", pos);
}
void cdll_delete_beg()
{
    node *temp;
    if (start == NULL)
    {
        printf("\n No nodes exist..");
        getch();
        return;
    }
    else
    {
        nodectr--;
        if (nodectr == 0)
        {
            free(start);
            start = NULL;
        }
        else
        {
            temp = start;
            start = start->right;
            temp->left->right = start;
            start->left = temp->left;
            free(temp);
        }
        printf("\n Node deleted at Beginning..");
    }
}
void cdll_delete_last()
{
    node *temp;
    if (start == NULL)
    {
        printf("\n No nodes exist..");
        getch();
        return;
    }
    else
    {
        nodectr--;
        if (nodectr == 0)
        {
            free(start);
            start = NULL;
        }
        else
        {
            temp = start;
            while (temp->right != start)
                temp = temp->right;
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            free(temp);
        }
        printf("\n Node deleted from end ");
    }
}
void cdll_delete_mid()
{
    int ctr = 1, pos;
    node *temp;
    if (start == NULL)
    {
        printf("\n No nodes exist..");
        getch();
        return;
    }
    else
    {
        printf("\n Which node to delete: ");
        scanf("%d", &pos);
        if (pos > nodectr)
        {
            printf("\nThis node does not exist");
            getch();
            return;
        }
        if (pos > 1 && pos < nodectr)
        {
            temp = start;
            while (ctr < pos)
            {
                temp = temp->right;
                ctr++;
            }
            temp->right->left = temp->left;
            temp->left->right = temp->right;
            free(temp);
            printf("\n node deleted..");
            nodectr--;
        }
        else
        {
            printf("\n It is not a middle position..");
            getch();
        }
    }
}
void main(void)
{
    int ch, n;
    while (1)
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            printf("\n Enter Number of nodes to create: ");
            scanf("%d", &n);
            cdll_createlist(n);
            printf("\n List created..");
            break;
        case 2:
            cdll_insert_beg();
            break;
        case 3:
            cdll_insert_end();
            break;
        case 4:
            cdll_insert_mid();
            break;
        case 5:
            cdll_delete_beg();
            break;
        case 6:
            cdll_delete_last();
            break;
        case 7:
            cdll_delete_mid();
            break;
        case 8:
            cdll_display_left_right();
            break;
        case 9:
            cdll_display_right_left();
            break;
        case 10:
            exit(0);
        }
        getch();
    }
}