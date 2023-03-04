// Perform Tree Traversal Algorithm Inorder, PreOrder and PostOrder.

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *left, *right;
} BSTNode;

BSTNode *insert(BSTNode *, int);
BSTNode *create();

void inorder(BSTNode *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        printf("%5d", T->data);
        inorder(T->right);
    }
}
void preorder(BSTNode *T)
{
    if (T != NULL)
    {
        printf("%5d", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}
void postOrder(BSTNode *T)
{
    if (T != NULL)
    {
        postOrder(T->left);
        postOrder(T->right);
        printf("%5d", T->data);
    }
}
int main()
{
    BSTNode *root, *p;
    root = create();
    printf("\nInorder BST traversal on the tree \n");
    inorder(root);
    printf("\nPreOrder BST traversal on the tree \n");
    preorder(root);
    printf("\nPostOrder BST traversal on the tree \n");
    postOrder(root);
    return 0;
}

BSTNode *create()
{
    int n, x, i;
    BSTNode *root;
    root = NULL;
    printf("Enter the no. of root : ");
    scanf("%d", &n);
    printf("Enter the elements of the BST : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    return (root);
}

BSTNode *insert(BSTNode *T, int x)
{
    BSTNode *p, *q, *r; // r-> new node  T-> root  q-> prev 
    r = (BSTNode *)malloc(sizeof(BSTNode));
    r->data = x;
    r->left = NULL;
    r->right = NULL;
    if (T == NULL)
        return (r);
    p = T;
    while (p != NULL)
    {
        q = p;
        if (x > p->data)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    if (x > q->data)
    {
        q->right = r;
    }
    else
    {
        q->left = r;
    }
    return (T);
}
