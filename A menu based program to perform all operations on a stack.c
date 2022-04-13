/*A menu based program to perform all operations on a stack*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
typedef struct 
    {
        int ele[MAX];
        int top;
    }stack;
void push(stack *,int);
int pop(stack *);
int peek(stack *);
int isfull(stack);
int isempty(stack);
void main()
    {
        stack s;
        int ch, element;
        s.top = -1;
        while(1)
            {
                printf("\n\nMenu of operations.");
                printf("\n\n1.push");
                printf("\n\n2.pop");
                printf("\n\n3.peek");
                printf("\n\n4.exit");
                printf("\n\nEnter your choice:");
                scanf("%d",&ch);
                switch(ch)
                    {
                        case 1: if(isfull(s))
                                    printf("Stack is full.");
                                else
                                    {
                                        printf("Enter element to be pushed:");
                                        scanf("%d", &element);
                                        push(&s, element);
                                    }
                                break;
                        case 2: if(isempty(s))
                                    printf("Stack is empty.");
                                else
                                    {
                                        element = pop(&s);
                                        printf("Popped element=%d", element);
                                    }
                                break;
                        case 3: if(isempty(s))
                                    printf("Stack is empty.");
                                else
                                    {
                                        element = peek(&s);
                                        printf("Peeked element=%d", element);
                                    }
                                break;
                        case 4: printf("Bye Bye");
                                    exit(0);
                        default:
                            printf("Wrong choice.");
                    }
                    getch();
            }
    }
void push(stack *s,int element)
    {
        s->ele[++s->top] = element;
    }
int pop(stack *s)
    {
        return (s->ele[s->top--]);
    }    
int peek(stack *s)
    {
        return (s->ele[s->top]);
    }    
int isfull(stack s)
    {
        if(s.top==MAX-1)
            return 1;
        else
            return 0;
    }    
int isempty(stack s)
    {
        if(s.top==-1)
            return 1;
        else
            return 0;
    }    