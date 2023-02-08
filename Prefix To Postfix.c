/* Program to convert prefix to postfix expression */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100
void pop(char *a1);
void push(char *str);
char stack[MAX][MAX];
int top = -1;
void main()
{
    char s[MAX], str1[MAX], str2[MAX], str[MAX];
    char s1[2], temp[2];
    int i = 0;
    printf("Enter the prefix expression; ");
    gets(s);
    strrev(s);
    while (s[i] != 0)
    {
        if (s[i] == ' ') /*skip whitespace, if any */
            i++;
        if (s[i] == '^' || s[i] == '*' || s[i] == '-' || s[i] == '+' || s[i] == '/')
        {
            pop(str1);
            pop(str2);
            temp[0] = s[i];
            temp[1] = '\0';
            strcat(str1, str2);
            strcat(str1, temp);
            strcpy(str, str1);
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
    printf("\nThe postfix expression is: %s", stack[0]);
}
void pop(char *a1)
{
    if (top == -1)
    {
        printf("\nStack is empty");
        return;
    }
    else
    {
        strcpy(a1, stack[top]);
        top--;
    }
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