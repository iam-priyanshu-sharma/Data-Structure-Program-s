/* Program to convert an infix to prefix expression */
#include <conio.h>
#include <string.h>
char prefix[50];
char infix[50];
char opstack[50]; /* operator stack */
int j, top = 0;
void insert_beg(char ch)
{
    int k;
    if (j == 0)
        prefix[0] = ch;
    else
    {
        for (k = j + 1; k > 0; k--)
            prefix[k] = prefix[k - 1];
        prefix[0] = ch;
    }
    j++;
}
int lesspriority(char op, char op_at_stack)
{
    int k;
    int pv1; /* priority value of op */
    int pv2; /* priority value of op_at_stack */
    char operators[] = {'+', '-', '*', '/', '%', '^', ')'};
    int priority_value[] = {0, 0, 1, 1, 2, 3, 4};
    if (op_at_stack == ')')
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
void push(char op) /* op – operator */
{
    if (top == 0)
    {
        opstack[top] = op;
        top++;
    }
    else
    {
        if (op != ')')
        {
            /* before pushing the operator 'op' into the stack check priority of op
            with top of operator stack if less pop the operator from stack then push into
            postfix string else push op onto stack itself */
            while (lesspriority(op, opstack[top - 1]) == 1 && top > 0)
            {
                insert_beg(opstack[--top]);
            }
        }
        opstack[top] = op; /* pushing onto stack */
        top++;
    }
}
void pop()
{
    while (opstack[--top] != ')') /* pop until ')' comes; */
        insert_beg(opstack[top]);
}
void main()
{
    char ch;
    int l, i = 0;
    printf("\n Enter Infix Expression : ");
    gets(infix);
    l = strlen(infix);
    while (l > 0)
    {
        ch = infix[--l];
        switch (ch)
        {
        case ' ':
            break;
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            push(ch); /* check priority and push */
            break;
        case '(':
            pop();
            break;
        default:
            insert_beg(ch);
        }
    }
    while (top > 0)
    {
        insert_beg(opstack[--top]);
        j++;
    }
    prefix[j] = '\0';
    printf("\n Infix Expression : %s ", infix);
    printf("\n Prefix Expression : %s ", prefix);
    getch();
}