/* C Program for stack operations using switch case*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

int stack_arr[MAX];
int top = -1;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Pushn");
        printf("\n2.Popn");
        printf("\n3.Display the top elementn");
        printf("\n4.Display all stack elementsn");
        printf("\n5.Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("nEnter the item to be pushed : ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            printf("nPopped item is : %dn", item);
            break;
        case 3:
            printf("nItem at the top is : %dn", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("nWrong choicen");
        } /*End of switch*/
    }     /*End of while*/

    return 0;

} /*End of main()*/

void push(int item)
{
    if (isFull())
    {
        printf("nStack Overflown");
        return;
    }
    top = top + 1;
    stack_arr[top] = item;
} /*End of push()*/

int pop()
{
    int item;
    if (isEmpty())
    {
        printf("nStack Underflown");
        exit(1);
    }
    item = stack_arr[top];
    top = top - 1;
    return item;
} /*End of pop()*/

int peek()
{
    if (isEmpty())
    {
        printf("nStack Underflown");
        exit(1);
    }
    return stack_arr[top];
} /*End of peek()*/

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
} /*End of isEmpty*/

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
} /*End of isFull*/

void display()
{
    int i;
    if (isEmpty())
    {
        printf("nStack is emptyn");
        return;
    }
    printf("nStack elements :nn");
    for (i = top; i >= 0; i--)
        printf(" %dn", stack_arr[i]);
    printf("n");
} /*End of display()*/