#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} splay;
splay *newnode(int key)
{
    splay *nnode = (splay *)malloc(sizeof(splay));
    nnode->right = nnode->left = NULL;
    nnode->data = key;
    return nnode;
}
splay *rightrotate(splay *y)
{
    splay *x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}
splay *leftrotate(splay *x)
{
    splay *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
splay *splaying(splay *root, int key)
{
    // Base case
    if (root == NULL || root->data == key)
        return root;
    // Left subtree
    if (key < root->data)
    {
        if (root->left == NULL)
            return root;
        if (key < root->left->data) // L-L rotation
        {
            // bring the node up by splaying
            root->left->left = splaying(root->left->left, key);
            root = rightrotate(root);
        }
        else if (key > root->left->data) // L-R rotation
        {
            root->left->right = splaying(root->left->right, key);
            root->left = leftrotate(root->left);
        }
        return (root->left == NULL) ? root : rightrotate(root);
    }
    else
    {
        if (root->right == NULL)
            return root;
        if (key > root->right->data) // R-R rotation
        {
            // bring the node up
            root->right->right = splaying(root->right->right, key);
            root = leftrotate(root);
        }
        else if (key < root->right->data) // R-L rotation
        {
            // bring the node up
            root->right->left = splaying(root->right->left, key);
            root->right = rightrotate(root->right);
        }
        return (root->right == NULL) ? root : leftrotate(root);
    }
}
splay *insert(splay *root, int key)
{
    // base case
    if (root == NULL)
        return newnode(key);
    // if left subtree
    if (key < root->data)
        root->left = insert(root->left, key);
    // right subtree
    if (key > root->data)
        root->right = insert(root->right, key);
    return splaying(root, key);
}
splay *inpre(splay *root)
{
    while (root && root->right != NULL)
        root = root->right;
    return root;
}
splay *delete(splay *root, int key)
{
    // base case
    if (root == NULL)
        return root;
    if (key == root->data)
    {
        // 0 child (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // 1 child
        // left
        if (root->left != NULL && root->right == NULL)
        {
            splay *temp = root->left;
            free(root);
            return temp;
        }
        // right
        if (root->left == NULL && root->right != NULL)
        {
            splay *temp = root->right;
            free(root);
            return temp;
        }
        // 2 children
        if (root->left != NULL && root->right != NULL)
        {
            int val = inpre(root->left)->data;
            root->data = val;
            root->left = delete (root->left, val);
        }
        return splaying(root, key);
    }
    else if (key < root->data)
    {
        root->left = delete (root->left, key);
        return root;
    }
    else
    {
        root->right = delete (root->right, key);
        return root;
    }
}
void inorder(splay *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *root = newnode(100);
    root = insert(root, 25);
    root = insert(root, 35);
    root = insert(root, 75);
    root = insert(root, 55);
    root = insert(root, 27);
    root = delete(root, 100);
    printf("inorder traversal of the modified Splay tree is \n");
    inorder(root);
    return 0;
}