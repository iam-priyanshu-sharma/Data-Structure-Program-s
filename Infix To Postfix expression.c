/* Program to convert an infix to postfix expression */
#include <stdio.h>
#include <conio.h>
#include <string.h>
char postfix[50];
char infix[50];
char opstack[50]; /* operator stack */
int i, j, top = 0;
int lesspriority(char op, char op_at_stack)
{
    int k;
    int pv1; /* priority value of op */
    int pv2; /* priority value of op_at_stack */
    char operators[] = {'+', '-', '*', '/', '%', '^', '('};
    int priority_value[] = {0, 0, 1, 1, 2, 3, 4};
    if (op_at_stack == '(')
        return 0;
    for (k = 0; k < 6; k++)
    {
        if (op == operators[k])
            pv1 = priority_value[k];
    }
    for (k = 0; k < 6; k++)
    {
        if (op_at_stack == operators[k])
            pv2 = priority_value[k];
    }
    if (pv1 < pv2)
        return 1;
    else
        return 0;
}
void push(char op) /* op - operator */
{
    /* before pushing the operator
    'op' into the stack check priority
    of op with top of opstack if less
    then pop the operator from stack
    then push into postfix string else
    push op onto stack itself */
    if (top == 0)
    {
        opstack[top] = op;
        top++;
    }
    else
    {
        if (op != '(')
        {
            while (lesspriority(op, opstack[top - 1]) == 1 && top > 0)
            {
                postfix[j] = opstack[--top];
                j++;
            }
        }
        opstack[top] = op; /* pushing onto stack */
        top++;
    }
}
pop()
{
    while (opstack[--top] != '(') /* pop until '(' comes */
    {
        postfix[j] = opstack[top];
        j++;
    }
}
void main()
{
    char ch;
    printf("\n Enter Infix Expression : ");
    gets(infix);
    while ((ch = infix[i++]) != 0)
    {
        switch (ch)
        {
        case ' ':
            break;
        case '(':
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            push(ch); /* check priority and push */
            break;
        case ')':
            pop();
            break;
        default:
            postfix[j] = ch;
            j++;
        }
    }
    while (top >= 0)
    {
        postfix[j] = opstack[--top];
        j++;
    }
    postfix[j] = '\0';
    printf("\n Infix Expression : %s ", infix);
    printf("\n Postfix Expression : %s ", postfix);
    getch();
}