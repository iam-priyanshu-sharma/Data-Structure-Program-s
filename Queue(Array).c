/*Source code for Queue operations using array*/
#include <stdio.h>
#include <conio.h>
#define MAX 6
int Q[MAX];
int front, rear;
void insertQ()
{
    int data;
    if (rear == MAX)
    {
        printf("\n Linear Queue is full");
        return;
    }
    else
    {
        printf("\n Enter data: ");
        scanf("%d", &data);
        Q[rear] = data;
        rear++;
        printf("\n Data Inserted in the Queue ");
    }
}
void deleteQ()
{
    if (rear == front)
    {
        printf("\n\n Queue is Empty..");
        return;
    }
    else
    {
        printf("\n Deleted element from Queue is %d", Q[front]);
        front++;
    }
}
void displayQ()
{
    int i;
    if (front == rear)
    {
        printf("\n\n\t Queue is Empty");
        return;
    }
    else
    {
        printf("\n Elements in Queue are: ");
        for (i = front; i < rear; i++)
        {
            printf("%d\t", Q[i]);
        }
    }
}
int menu()
{
    int ch;
    printf("\n \tQueue operations using ARRAY..");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}
void main()
{
    int ch;
    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            insertQ();
            break;
        case 2:
            deleteQ();
            break;
        case 3:
            displayQ();
            break;
        case 4:
            return;
        }
        getch();
    } while (1);
}