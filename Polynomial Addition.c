/* Source code for polynomial addition with help of linked list */
#include <stdio.h>
#include <conio.h>
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
void add_poly(node *p1, node *p2)
{
    node *newnode;
    while (1)
    {
        if (p1 == NULL || p2 == NULL)
            break;
        if (p1->expo == p2->expo)
        {
            printf("+ %.2f X ^%d", p1->coef + p2->coef, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            if (p1->expo < p2->expo)
            {
                printf("+ %.2fX ^%d", p1->coef, p1->expo);
                p1 = p1->next;
            }
            else
            {
                printf(" + %.2fX ^%d", p2->coef, p2->expo);
                p2 = p2->next;
            }
        }
    }
    while (p1 != NULL)
    {
        printf("+ %.2f X ^%d", p1->coef, p1->expo);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        printf("+ %.2f X ^%d", p2->coef, p2->expo);
        p2 = p2->next;
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
    printf("\n Resultant Polynomial : ");
    add_poly(poly1, poly2);
    display(poly3);
    getch();
}