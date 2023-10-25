#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} bst;
bst *insert(bst *root, int key)
{
    if (root == NULL)
    {
        root = (bst *)malloc(sizeof(bst));
        root->data = key;
        root->left = root->right = NULL;
        return root;
    }
    if (key > root->data)
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);
    return root;
}
void InOrder(bst *ptr)
{
    if (ptr != NULL)
    {
        InOrder(ptr->left);
        printf("%d ", ptr->data);
        InOrder(ptr->right);
    }
}
int getheight(bst *node)
{
    if (node == NULL)
        return 0;
    int rightheight = getheight(node->right);
    int leftheight = getheight(node->left);
    return 1 + (leftheight > rightheight ? leftheight : rightheight);
}
bst *inpre(bst *node)
{
    while (node && node->right != NULL)
        node = node->right;
    return node;
}
bst *delete(bst *root, int key){
    // base case
    if(root == NULL)
        return root;
    else if(root->data == key)
    {
        // 0 child (leaf node)
        if(root->right == NULL && root->left == NULL)
        {
            free(root);
            return NULL;
        }

        // 1 child
        // left child
        if(root->left != NULL && root->right == NULL)
        {
            bst *temp = root->left;
            free(root);
            return temp;
        }
        // right child
        if(root->left == NULL && root->right != NULL)
        {
            bst *temp = root->right;
            free(root);
            return temp;
        }

        // 2 children
        if(root->left != NULL && root->right != NULL)
        {
            int val = inpre(root->left)->data;
            root->data = val;
            root->left = delete(root->left, val);
            return root;
        }
    }
    else if(root->data < key)
    {
        root->right = delete(root->right, key);
        return root;
    }
    else
    {
        root->left = delete(root->left, key);
        return root;
    }
}
int main()
{
    bst *root = (bst *)malloc(sizeof(bst));
    root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    InOrder(root);
    root = delete(root, 7);
    InOrder(root);
    return 0;
}