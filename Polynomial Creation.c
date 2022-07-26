/* Source code for polynomial creation with help of linked list */
#include <conio.h>
#include <stdio.h>
#include <malloc.h>
struct link
{
    float coef;
    int expo;
    struct link *next;
};
typedef struct link node;
node *getnode()
{
    node *tmp;
    tmp = (node *)malloc(sizeof(node));
    printf("\n Enter Coefficient : ");
    fflush(stdin);
    scanf("%f", &tmp->coef);
    printf("\n Enter Exponent : ");
    fflush(stdin);
    scanf("%d", &tmp->expo);
    tmp->next = NULL;
    return tmp;
}
node *create_poly(node *p)
{
    char ch;
    node *temp, *newnode;
    while (1)
    {
        printf("\n Do U Want polynomial node (y/n): ");
        ch = getche();
        if (ch == 'n')
            break;
        newnode = getnode();
        if (p == NULL)
            p = newnode;
        else
        {
            temp = p;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    return p;
}
void display(node *p)
{
    node *t = p;
    while (t != NULL)
    {
        printf("+ %.2f", t->coef);
        printf("X^ %d", t->expo);
        t = t->next;
    }
}
void main()
{
    node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    printf("\nEnter First Polynomial..(in ascending-order of exponent)");
    poly1 = create_poly(poly1);
    printf("\nEnter Second Polynomial..(in ascending-order of exponent)");
    poly2 = create_poly(poly2);
    printf("\n Enter Polynomial 1: ");
    display(poly1);
    printf("\n Enter Polynomial 2: ");
    display(poly2);
    getch();
}