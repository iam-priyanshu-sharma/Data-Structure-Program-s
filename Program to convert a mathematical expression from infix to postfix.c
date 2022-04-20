/*Program to convert a mathematical expression from infix to postfix*/
#include<stdio.h>
#include<conio.h>
#define MAX 15
typedef struct
	{
	    int top;
	    char ele[MAX];
	}stack;
void push(stack *,char);
char pick(stack *);
char pop(stack *);
int isfull(stack *);
int isempty(stack *);
int isdigit(char);
int isalpha(char);
int prior(char);
void main()
	{
	    char *in,*post,*t,*s;
	    stack st;
	    st.top=-1;
	    printf("Enter an expression:");
	    gets(in);
	    s=in;
	    post=t;
	    while(*s)
	        {
	            if(*s==' '||*s=='\t')
	                {
	                    s++;
	                }
	            else if(*s=='(')
	                {
	                    push(&st,*s);
	                    s++;
	                }
	            else if(*s==')')
	                {
	                    while((!isempty(&st)&&pick(&st)!='('))
		                    {
		                        *t=pop(&st);
		                        t++;
		                    }
	                    if(isempty(&st))
		                    {
		                        printf("Error in expression.");
		                        getch();
		                        return;
		                    }
	                    else
		                    {
		                        pop(&st);
		                        s++;
		                    }
	                }
	            else if(isdigit(*s)||isalpha(*s))
	                {
                        *t=*s;
	                    t++;
                        s++;
	                }
	            else if(*s=='+'||*s=='-'||*s=='*'||*s=='/'||*s=='%'||*s=='^')
	                {
	                    while((!isempty(&st)&&pick(&st)!='(')&&prior(pick(&st))>=prior(*s))
		                    {
		                        *t=pop(&st);
		                        t++;
		                    }
	                    push(&st,*s);
	                    s++;
	                }
	            else
	                {
	                    printf("Invalid symbol in the expression");
	                    getch();
	                    return;
	                }
	        }
	    while(!isempty(&st)&&pick(&st)!='(')
	        {
	            *t=pop(&st);
	            t++;
	        }
	    if(pick(&st)=='(')
	        {
	            printf("Error:Mismatched parentheses");
	            getch();
	            return;
	        }
	    *t='\0';
	    printf("Postfix=%s",post);
	    getch();
	}
void push(stack *s, char x)
	{
	    s->ele[++s->top]=x;
	}
char pop(stack *s)
	{
	    return(s->ele[s->top--]);
	}
char pick(stack *s)
	{
	    return(s->ele[s->top]);
	}
int isempty(stack *s)
	{
	    if(s->top==-1)
	        return 1;
	    else
	        return 0;
	}
int isfull(stack *s)
	{
	    if(s->top==MAX-1)
	        return 1;
	    else
	        return 0;
	}
int prior(char ch)
	{
	    if(ch=='+'||ch=='-')
	        return 1;
	    else if(ch=='^')
	        return 3;
	    else
	        return 2;
	}
int isdigit(char ch)
	{
	    if(ch>47&&ch<58)
	        return 1;
	    else
	        return 0;
	}
int isalpha(char ch)
	{
	    if(ch>64&&ch<91||ch>96&&ch<123)
	        return 1;
	    else
	        return 0;
	   }

