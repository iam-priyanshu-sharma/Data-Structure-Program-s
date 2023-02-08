#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Maximum stack size
#define MAX_SIZE 100

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};
typedef struct Node NODE;
NODE *root = NULL;

// <------  INITIALIZATION O FTHE STACK AND IT'S BASIC OPERATION  ---->
struct Stack
{
    int size;
    int top;
    NODE **arr;
};

struct Stack *InitializeStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (struct Node **)malloc(stack->size * sizeof(struct Node *));
    return stack;
}

// opertaion on stack
int isFull(struct Stack *stack)
{
    return stack->top == stack->size - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
void push(struct Stack *stack, NODE *node)
{
    if (isFull(stack))
        return;
    stack->top++;
    stack->arr[stack->top] = node;
}

NODE *pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->arr[stack->top--];
}

//  <-------- insertation into BST ---->
void Insert(int key)
{
    NODE *t = root;
    NODE *p;
    NODE *r;

    // root is empty
    if (root == NULL)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }

    // Now t points at NULL and r points at insert location
    p = (NODE *)malloc(sizeof(NODE));
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

// <---- for part-2 --->
int TotalNodes(NODE *p)
{
    int x, y;
    if (p != NULL)
    {
        x = TotalNodes(p->lchild);
        y = TotalNodes(p->rchild);
        return x + y + 1;
    }
    return 0;
}
int leaves(NODE *p)
{
    if (p == NULL)
        return 0;
    if (p->lchild == NULL && p->rchild == NULL)
        return 1;
    return leaves(p->lchild) + leaves(p->rchild);
}
int internalNodes(NODE *p)
{
    return TotalNodes(p) - leaves(p);
}
int maxfunction(int a, int b)
{
    return a > b ? a : b;
}
int Height(NODE *p)
{
    int x, y;
    if (p != NULL)
    {
        x = Height(p->lchild);
        y = Height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return -1;
}

// <---- for deleting a Node from BST  ------>
NODE *findMin(NODE *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild)
        return findMin(p->lchild);
    else
        return p;
}
NODE *del(NODE *p, int data)
{
    NODE *temp;
    if (p == NULL)
    {
        printf("\nElement not found");
    }
    else if (data < p->data)
    {
        p->lchild = del(p->lchild, data);
    }
    else if (data > p->data)
    {
        p->rchild = del(p->rchild, data);
    }
    else
    {
        // we have 2 children of the node then replace with min element in rchild subtree
        if (p->rchild && p->lchild)
        { /* Here we will replace with minimum element in the rchild sub tree */
            temp = findMin(p->rchild);
            p->data = temp->data;
            p->rchild = del(p->rchild, temp->data); // no longer needed
        }
        else
        {
            /* If there is only one or zero children then we can directly remove it from the tree and connect its parent to its child */
            temp = p;
            if (p->lchild == NULL)
                p = p->rchild;
            else if (p->rchild == NULL)
                p = p->lchild;
            free(temp); // no longer needed
        }
    }
    return p;
}

// <----- Preorder Traversal ------>
void preorder(NODE *p)
{

    struct Stack *stack = InitializeStack(MAX_SIZE);
    while (p != NULL || !isEmpty(stack))
    {
        if (p != NULL)
        {
            printf("%d ", p->data);
            push(stack, p);
            p = p->lchild;
        }
        else
        {
            p = pop(stack);
            p = p->rchild;
        }
    }
}

// <----- Inorder Traversal ------>
void inorder(NODE *p)
{
    struct Stack *stack = InitializeStack(MAX_SIZE);
    while (p != NULL || !isEmpty(stack))
    {
        if (p != NULL)
        {

            push(stack, p);
            p = p->lchild;
        }
        else
        {
            p = pop(stack);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

// <----- Postorder Traversal ------>
void postorder(NODE *p)
{
    if (p == NULL)
        return;
    struct Stack *stack = InitializeStack(MAX_SIZE);
    do
    {
        // Move to left dmost node
        while (p != NULL)
        {
            // Push root's right child and then root to stack.
            if (p->rchild != NULL)
                push(stack, p->rchild);
            push(stack, p);

            // Set root as root's left child
            p = p->lchild;
        }

        // Pop an item from stack and set it as root
        p = pop(stack);

        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before p
        if (p->rchild != NULL && stack->arr[stack->top] == p->rchild)
        {
            pop(stack);     // remove right child from stack
            push(stack, p); // push root back to stack
            p = p->rchild;  // change root so that the right
                            // child is processed next
        }
        else // Else print root's data and set root as NULL
        {
            printf("%d ", p->data);
            p = NULL;
        }
    } while (!isEmpty(stack));
}

int main()
{
    int t, i, data, n;
    while (1)
    {

        printf("\n1.Insertion.\n2.Delete.");
        printf("\n3.Display the number of leaves, internal nodes, and the height of the tree.");
        printf("\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &t);
        switch (t)
        {

        case 1:
            printf("\nvalues: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                Insert(data);
            }
            break;
        case 2:
            printf("\nEnter the element to delete: ");
            scanf("%d", &data);
            root = del(root, data);
            break;
        case 3:
            printf("Number of leaves : %d\n", leaves(root));
            printf("Number of internal nodes : %d\n", internalNodes(root));
            printf("Height of tree : %d\n", Height(root));
            break;
        case 4:
            printf("\nInorder Traversal: \n");
            inorder(root);
            break;
        case 5:
            printf("\nPreorder Traversal: \n");
            preorder(root);
            break;
        case 6:
            printf("\nPostorder Traversal: \n");
            postorder(root);
            break;
        case 7:
            exit(0);
        default:
            printf("\nWrong choice choose another key");
            break;
        };
    }
    return 0;
}