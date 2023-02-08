/*Program to convert a mathematical expression from infix to prefix*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20
typedef struct
	{
	    int top;
	    int ele[MAX];
	}stack;
void push(stack *,char);
char pop(stack *);
char pick(stack);
int isfull(stack);
int isempty(stack);
int isdigit(char);
int isalpha(char);
int prior(char);
char *convert(char *);
void main()
	{
	    char in[50],*pre;
	    printf("\nEnter a mathematical expression:");
	    gets(in);
	    pre=convert(in);
	    printf("\nPrefix notation= %s",pre);
	    getch();
	}
void push(stack *st,char ch)
	{
	    st->ele[++st->top]=ch;
	}
char pop(stack *st)
	{
	    return(st->ele[st->top--]);
	}
char pick(stack st)
	{
	    return(st.ele[st.top]);
	}
int isdigit(char x)
	{
	    if(x>47&&x<58)
	        return 1;
	    else
	        return 0;
	}
int isalpha(char x)
	{
	    if((x>64&&x<91)||(x>96&&x<123))
	        return 1;
	    else
	        return 0;
	}
int prior(char x)
	{
	    if(x=='/'||x=='*'||x=='%')
	        return 1;
	    else if(x=='+'||x=='-')
	        return 0;
	    else
	        return 2;
	}
int isempty(stack s)
	{
	    if(s.top==-1)
	        return 1;
	    else
	        return 0;
	}
int isfull(stack s)
	{
	    if(s.top==MAX-1)
	        return 1;
	    else
	        return 0;
	}
char *convert(char *s)
	{
	    stack st;
	    char *t;
	    st.top=-1;
	    strrev(s);
	    *(t+strlen(s))='\0';
	    t=t+strlen(s)-1;
	    while(*s)
	        {
	            if(*s==' '||*s=='\t')
	                {
	                    s++;
	                    continue;
	                }
	            if(isdigit(*s)||isalpha(*s))
	                {
	                    *t=*s;
	                    t--;
	                    s++;
	                    continue;
	                }
	            if(*s==')')
	                {
	                    push(&st,*s);
	                    s++;
	                    continue;
	                }
	            if(*s=='+'||*s=='-'||*s=='*'||*s=='/'||*s=='%'||*s=='^')
	                {
	                    while(!isempty(st)&&(pick(st)!=')')&&prior(pick(st))>prior(*s))
		                    {
		                        *t=pop(&st);
		                        t--;
		                    }
	                    push(&st,*s);
	                    s++;
	                }
	            if(*s=='(')
	                {
	                    while(!isempty(st)&&pick(st)!=')')
	                        {
	                            *t=pop(&st);
	                            t--;
	                        }
	                    if(isempty(st))
		                    printf("\n Expression invalid");
	                    else
		                    {
		                        pop(&st);
		                        s++;
		                    }
	                }
	        }
	    while(!isempty(st))
	        {
	            *t=pop(&st);
	            t--;
	        }
	    t++;
	    return t;
	}