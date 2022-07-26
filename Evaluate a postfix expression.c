/* Program to evaluate a postfix expression */
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 20
int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}
void main(void)
{
    char postfix[MAX];
    int val;
    char ch;
    int i = 0, top = 0;
    float val_stack[MAX], val1, val2, res;
    printf("\n Enter a postfix expression: ");
    scanf("%s", postfix);
    while ((ch = postfix[i]) != 0)
    {
        if (isoperator(ch) == 1)
        {
            val2 = val_stack[--top];
            val1 = val_stack[--top];
            switch (ch)
            {
            case '+':
                res = val1 + val2;
                break;
            case '-':
                res = val1 - val2;
                break;
            case '*':
                res = val1 * val2;
                break;
            case '/':
                res = val1 / val2;
                break;
            case '^':
                res = pow(val1, val2);
                break;
            }
            val_stack[top] = res;
        }
        else
            val_stack[top] = ch - 48; /*convert character digit to integer digit */
        top++;
        i++;
    }
    printf("\n Values of %s is : %f ", postfix, val_stack[0]);
    getch();
}