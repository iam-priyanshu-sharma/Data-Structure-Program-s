/* Binary Tree Creation and Traversal Using Arrays */
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
int ctr;
node *tree[100];
node *getnode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("\n Enter Data: ");
    scanf("%s", temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
void create_fbinarytree()
{
    int j, i = 0;
    printf("\n How many nodes you want: ");
    scanf("%d", &ctr);
    tree[0] = getnode();
    j = ctr;
    j--;
    do
    {
        if (j > 0) /* left child */
        {
            tree[i * 2 + 1] = getnode();
            tree[i]->lchild = tree[i * 2 + 1];
            j--;
        }
        if (j > 0) /* right child */
        {
            tree[i * 2 + 2] = getnode();
            j--;
            tree[i]->rchild = tree[i * 2 + 2];
        }
        i++;
    } while (j > 0);
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
void levelorder()
{
    int j;
    for (j = 0; j < ctr; j++)
    {
        if (tree[j] != NULL)
            printf("%3s", tree[j]->data);
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
    {
        return 0;
    }
    if (root->lchild == NULL && root->rchild == NULL)
        return 0;
    else
        return (1 + max(height(root->lchild), height(root->rchild)));
}
void main()
{
    // int i;
    create_fbinarytree();
    printf("\n Inorder Traversal: ");
    inorder(tree[0]);
    printf("\n Preorder Traversal: ");
    preorder(tree[0]);
    printf("\n Postorder Traversal: ");
    postorder(tree[0]);
    printf("\n Level Order Traversal: ");
    levelorder();
    printf("\n Leaf Nodes: ");
    print_leaf(tree[0]);
    printf("\n Height of Tree: %d ", height(tree[0]));
}