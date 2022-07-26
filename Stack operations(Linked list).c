/* Source code for stack operations, using linked list */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
void push();
void pop();
void display();
typedef struct stack node;
node *start = NULL;
node *top = NULL;
node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("\n Enter data ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    return temp;
}
void push(node *newnode)
{
    node *temp;
    if (newnode == NULL)
    {
        printf("\n Stack Overflow..");
        return;
    }
    if (start == NULL)
    {
        start = newnode;
        top = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        top = newnode;
    }
    printf("\n\n\t Data pushed into stack");
}
void pop()
{
    node *temp;
    if (top == NULL)
    {
        printf("\n\n\t Stack underflow");
        return;
    }
    temp = start;
    if (start->next == NULL)
    {
        printf("\n\n\t Popped element is %d ", top->data);
        start = NULL;
        free(top);
        top = NULL;
    }
    else
    {
        while (temp->next != top)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        printf("\n\n\t Popped element is %d ", top->data);
        free(top);
        top = temp;
    }
}
void display()
{
    node *temp;
    if (top == NULL)
    {
        printf("\n\n\t\t Stack is empty ");
    }
    else
    {
        temp = start;
        printf("\n\n\n\t\t Elements in the stack: \n");
        printf("%5d ", temp->data);
        while (temp != top)
        {
            temp = temp->next;
            printf("%5d ", temp->data);
        }
    }
}
char menu()
{
    char ch;
    printf("\n \tStack operations using pointers.. ");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Push ");
    printf("\n 2. Pop ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    ch = getche();
    return ch;
}
void main()
{
    char ch;
    node *newnode;
    do
    {
        ch = menu();
        switch (ch)
        {
        case '1':
            newnode = getnode();
            push(newnode);
            break;
        case '2':
            pop();
            break;
        case '3':
            display();
            break;
        case '4':
            return;
        }
    } while (ch != '4');
    getch();
}