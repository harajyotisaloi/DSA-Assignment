//Write a program to create a binary search tree using link representation and display the elements in preorder, in order and post order using recursive function. 
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
} *root = NULL;

struct Node *insert(struct Node *, int);
struct Node *newNode(int);
void InOrder(struct Node *);
void PreOrder(struct Node *);
void PostOrder(struct Node *);
void freeTree(struct Node *);

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    else if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else
    {
        node->right = insert(node->right, key);
    }
    return node;
}

struct Node *newNode(int item)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->key = item;
    new->left = new->right = NULL;
    return new;
}

void InOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        InOrder(root->left);
        printf("%d ", root->key);
        InOrder(root->right);
    }
}

void PreOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->key);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->key);
    }
}

void freeTree(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    freeTree(node->left);
    freeTree(node->right);

    free(node);
}

int main()
{
    int choice, key;
    printf("\n   MENU   ");
    printf("\n1.Insert \n2.In-Order Traversal \n3.Pre-Order Traversal \n4.Post-Order Traversal \n5.Exit");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("\nIn-Order Traversal: \n");
            InOrder(root);
            printf("\n");
            break;
        case 3:
            printf("\nPre-Order Traversal: \n");
            PreOrder(root);
            printf("\n");
            break;
        case 4:
            printf("\nPost-Order Traversal: \n");
            PostOrder(root);
            printf("\n");
            break;
        case 5:
            printf("\nExiting...\n");
            freeTree(root);
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    } while (choice != 5);

    return 0;
}