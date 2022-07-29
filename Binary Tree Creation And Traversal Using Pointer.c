/* Binary Tree Creation and Traversal Using Pointers */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct tree
{
    struct tree *lchild;
    char data[10];
    struct tree *rchild;
};
typedef struct tree node;
node *Q[50];
int node_ctr;
node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("\n Enter Data: ");
    fflush(stdin);
    scanf("%s", temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
void create_binarytree(node *root)
{
    char option;
    node_ctr = 1;
    if (root != NULL)
    {
        printf("\n Node %s has Left SubTree(Y/N)", root->data);
        fflush(stdin);
        scanf("%c", &option);
        if (option == 'Y' || option == 'y')
        {
            root->lchild = getnode();
            node_ctr++;
            create_binarytree(root->lchild);
        }
        else
        {
            root->lchild = NULL;
            create_binarytree(root->lchild);
        }
        printf("\n Node %s has Right SubTree(Y/N) ", root->data);
        fflush(stdin);
        scanf("%c", &option);
        if (option == 'Y' || option == 'y')
        {
            root->rchild = getnode();
            node_ctr++;
            create_binarytree(root->rchild);
        }
        else
        {
            root->rchild = NULL;
            create_binarytree(root->rchild);
        }
    }
}
void make_Queue(node *root, int parent)
{
    if (root != NULL)
    {
        node_ctr++;
        Q[parent] = root;
        make_Queue(root->lchild, parent * 2 + 1);
        make_Queue(root->rchild, parent * 2 + 2);
    }
}
delete_node(node *root, int parent)
{
    int index = 0;
    if (root == NULL)
        printf("\n Empty TREE ");
    else
    {
        node_ctr = 0;
        make_Queue(root, 0);
        index = node_ctr - 1;
        Q[index] = NULL;
        parent = (index - 1) / 2;
        if (2 * parent + 1 == index)
            Q[parent]->lchild = NULL;
        else
            Q[parent]->rchild = NULL;
    }
    printf("\n Node Deleted ..");
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%3s", root->data);
        inorder(root->rchild);
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%3s", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%3s", root->data);
    }
}
void print_leaf(node *root)
{
    if (root != NULL)
    {
        if (root->lchild == NULL && root->rchild == NULL)
            printf("%3s ", root->data);
        print_leaf(root->lchild);
        print_leaf(root->rchild);
    }
}
int height(node *root)
{
    if (root == NULL)
        return -1;
    else
        return (1 + max(height(root->lchild), height(root->rchild)));
}
void print_tree(node *root, int line)
{
    int i;
    if (root != NULL)
    {
        print_tree(root->rchild, line + 1);
        printf("\n");
        for (i = 0; i < line; i++)
            printf(" ");
        printf("%s", root->data);
        print_tree(root->lchild, line + 1);
    }
}
void level_order(node *Q[], int ctr)
{
    int i;
    for (i = 0; i < ctr; i++)
    {
        if (Q[i] != NULL)
            printf("%5s", Q[i]->data);
    }
}
int menu()
{
    int ch;
    printf("\n 1. Create Binary Tree ");
    printf("\n 2. Inorder Traversal ");
    printf("\n 3. Preorder Traversal ");
    printf("\n 4. Postorder Traversal ");
    printf("\n 5. Level Order Traversal");
    printf("\n 6. Leaf Node ");
    printf("\n 7. Print Height of Tree ");
    printf("\n 8. Print Binary Tree ");
    printf("\n 9. Delete a node ");
    printf("\n 10. Quit ");
    printf("\n Enter Your choice: ");
    scanf("%d", &ch);
    return ch;
}
void main()
{
    int i, ch;
    node *root = NULL;
    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            if (root == NULL)
            {
                root = getnode();
                create_binarytree(root);
            }
            else
            {
                printf("\n Tree is already Created ..");
            }
            break;
        case 2:
            printf("\n Inorder Traversal: ");
            inorder(root);
            break;
        case 3:
            printf("\n Preorder Traversal: ");
            preorder(root);
            break;
            printf("\n Postorder Traversal: ");
            postorder(root);
            break;
        case 5:
            printf("\n Level Order Traversal ..");
            make_Queue(root, 0);
            level_order(Q, node_ctr);
            break;
        case 6:
            printf("\n Leaf Nodes: ");
            print_leaf(root);
            break;
        case 7:
            printf("\n Height of Tree: %d ", height(root));
            break;
        case 8:
            printf("\n Print Tree \n");
            print_tree(root, 0);
            break;
        case 9:
            delete_node(root, 0);
            break;
        case 10:
            exit(0);
        }
        getch();
    } while (1);
}