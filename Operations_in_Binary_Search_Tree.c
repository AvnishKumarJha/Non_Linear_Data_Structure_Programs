// Binary Search Tree Operations in C.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right); // two children
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int flag = 1;
int searchNode(struct node *temp, int value)
{
    struct node *root = NULL;

    if (temp->key == value)
    {
        flag = 0;
        return flag;
    }
    if (flag == 1 && temp->left != NULL)
    {
        searchNode(temp->left, value);
    }
    if (flag == 1 && temp->right != NULL)
    {
        searchNode(temp->right, value);
    }
}
void main()
{
    struct node *root = NULL;
    int n, data, choice;
    do
    {
        printf("\nEnter your choice :\n1.Insert\n2.Search\n3.Delete\n4.Exit\n: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the number of nodes to insert : ");
            scanf("%d", &n);
            printf("Enter the numbers to insert in the bst \n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        }
        case 2:
        {
            int search;
            printf("Enter the element to search : ");
            scanf("%d", &search);
            searchNode(root, search);
            if (flag == 1)
                printf("Element is present in the binary tree");
            else
                printf("Element is not present in the binary tree");
            break;
        }
        case 3:
        {
            int del;
            printf("Inorder traversal: ");
            inorder(root);
            printf("\nEnter the element to delete : ");
            scanf("%d", &del);
            printf("\nAfter deleting %d\n", del);
            root = deleteNode(root, del);
            printf("Inorder traversal: ");
            inorder(root);
        }
        }
    } while (choice != 4);
}
