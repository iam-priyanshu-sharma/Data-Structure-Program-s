/*A menu driven program to perform basic operations(enqueue,dequeue and peek) on a queue*/
#include<stdio.h>
#include<conio.h>
#define MAX 10
typedef struct
    {
        int a[MAX];
        int front, rear;
    }queue;
void enqueue(queue *, int);
int dequeue(queue *);
int peek(queue);
int isfull(queue);
int isempty(queue);
void main()
    {
        queue q;
        int ele, ch;
        q.front = 0;
        q.rear = -1;
        while(1)
            {
                printf("\n\tOperations on Queue.");
                printf("\n\t1.Enqueue");
                printf("\n\t2.Dequeue");
                printf("\n\t3.Peek");
                printf("\n\t0.Exit");
                printf("\n\tEnter your choice:");
                scanf("%d", &ch);
                if(ch==0)
                    break;
                else
                    {
                        switch (ch)
                            {
                                case 1: if(isfull(q))
                                            printf("\nQueue is full.No element can be enqueued.");
                                        else
                                            {
                                                printf("\nEnter element to enqueue:");
                                                scanf("%d", &ele);
                                                enqueue(&q, ele);
                                            }
                                        break;
                                case 2: if(isempty(q))
                                            printf("\nQueue is empty.No element can be dequeued.");
                                        else
                                            {
                                                ele = dequeue(&q);
                                                printf("\nDequeued element=%d", ele);
                                            }
                                        break;
                                case 3: if(isempty(q))
                                            printf("\nQueue is empty.No element can be peeked.");
                                        else
                                            {
                                                ele = peek(q);
                                                printf("Peeked element=%d", ele);
                                            }
                                        break;
                                default:printf("\nWrong choice.");
                            }
                        getch();
                    }    
            }
    }
void enqueue(queue *q,int ele)
    {
        int i;
        if(q->rear==MAX-1)
            {
                for (i = 0; q->front <= q->rear;i++)
                    q->a[i] = q->a[q->front++];
                q->front = 0;
                q->rear = i - 1;
            }
        q->a[++q->rear] = ele;
    }
int dequeue(queue *q)
    {
        int ele;
        ele = q->a[q->front++];
        if(q->front>q->rear)
            {
                q->front = 0;
                q->rear = -1;
            }
        return ele;
    }        
int peek(queue q)
    {
        return (q.a[q.front]);
    }    
int isfull(queue q)
    {
        if(q.front==0 && q.rear==MAX-1)
            return 1;
        else
            return 0;
    }    
int isempty(queue q)
    {
        if(q.front>q.rear)
            return 1;
        else
            return 0;
    }    
