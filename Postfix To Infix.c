/* Program to convert postfix to infix expression */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100
void pop(char *);
void push(char *);
char stack[MAX][MAX];
int top = -1;
void main()
{
    char s[MAX], str1[MAX], str2[MAX], str[MAX];
    char s1[2], temp[2];
    int i = 0;
    printf("\nEnter the postfix expression: ");
    gets(s);
    while (s[i] != 0)
    {
        if (s[i] == ' ') /*skip whitespace, if any*/
            i++;
        if (s[i] == '^' || s[i] == '*' || s[i] == '-' || s[i] == '+' || s[i] == '/')
        {
            pop(str1);
            pop(str2);
            temp[0] = '(';
            temp[1] = '\0';
            strcpy(str, temp);
            strcat(str, str2);
            temp[0] = s[i];
            temp[1] = '\0';
            strcat(str, temp);
            strcat(str, str1);
            temp[0] = ')';
            temp[1] = '\0';
            strcat(str, temp);
            push(str);
        }
        else
        {
            temp[0] = s[i];
            temp[1] = '\0';
            strcpy(s1, temp);
            push(s1);
        }
        i++;
    }
    printf("\nThe Infix expression is: %s", stack[0]);
}
void pop(char *a1)
{
    strcpy(a1, stack[top]);
    top--;
}
void push(char *str)
{
    if (top == MAX - 1)
        printf("\nstack is full");
    else
    {
        top++;
        strcpy(stack[top], str);
    }
}