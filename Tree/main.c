#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* newBranch(int data)
{
    struct Tree* newBranch = (struct Tree*) malloc(sizeof(struct Tree));
    newBranch->data = data;
    newBranch->right = NULL;
    newBranch->left = NULL;
    return newBranch;
};

void inOrder(struct Tree* tree)
{
    if(tree->left != NULL)
    {
        if(tree->left->left != NULL)
            inOrder(tree);
        printf("%d ", tree->left->data);
    }

    if(tree->data != NULL)
    {
        printf("%d ", tree->data);
    }

    if(tree->right != NULL)
    {
        printf("%d ", tree->right->data);
    }
}

int main()
{
    struct Tree* root = (struct Tree*) malloc(sizeof(struct Tree));
    struct Tree* rightNode = newBranch(5);
    struct Tree* leftNode = newBranch(7);
    struct Tree* leftGrandchild = newBranch(82);

    root->data = 12;
    root->right = rightNode;
    root->left = leftNode;
    leftNode->left = leftGrandchild;

    inOrder(root);
    return 0;
}
