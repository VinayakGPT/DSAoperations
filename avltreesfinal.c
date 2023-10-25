#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} avl;
int height(avl *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
avl *newnode(int key)
{
    avl *nnode = (avl *)malloc(sizeof(avl));
    nnode->data = key;
    nnode->left = nnode->right = NULL;
    nnode->height = 1;
    return nnode;
}
avl *rightrotate(avl *y)
{
    avl *x = y->left;
    avl *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->right), height(y->left)) + 1;
    x->height = max(height(x->right), height(x->left)) + 1;
    return x;
}
avl *leftrotate(avl *x)
{
    avl *y = x->right;
    avl *T2 = y->left;
    y->left = x;
    x->right = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return y;
}
int balancefactor(avl *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}
avl *insert(avl *node, int key)
{
    // if nothing exists, create node
    if (node == NULL)
        return newnode(key);
    // otherwise, perform normal BST insertion
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;
    // update height of node
    node->height = max(height(node->left), height(node->right)) + 1;
    int bf = balancefactor(node);

    // if balance factor is disturbed, check possibilities for rotations
    if (bf > 1 && key < node->left->data) // L-L rotation
        return rightrotate(node);
    if (bf < -1 && key > node->right->data) // R-R rotation
        return leftrotate(node);
    if (bf > 1 && key > node->left->data) // L-R rotation
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    if (bf < -1 && key < node->right->data) // R-L rotation
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node; // in case balance factor isn't disturbed
}
void search(avl *root, int key)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (root->data == key)
    {
        printf("Element found\n");
        return;
    }
    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}
avl *inpre(avl *node)
{
    while (node && node->right != NULL)
        node = node->right;
    return node;
}
avl *delete(avl *root, int key)
{
    // First perform normal BST deletion
    // base case
    if (root == NULL)
        return root;
    else if (root->data == key)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // 1 child
        // left child is not NULL
        if (root->left != NULL && root->right == NULL)
        {
            avl *temp = root->left;
            free(root);
            return temp;
        }
        // right child is not NULL
        if (root->left == NULL && root->right != NULL)
        {
            avl *temp = root->right;
            free(root);
            return temp;
        }
        // 2 children
        if (root->left != NULL && root->right != NULL)
        {
            int val = inpre(root->left)->data;
            root->data = val;
            root->left = delete (root->left, val);
            return root;
        }
    }
    else if (root->data < key)
    {
        root->right = delete (root->right, key);
        return root;
    }
    else
    {
        root->left = delete (root->left, key);
        return root;
    }
    // Update height of root node
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = balancefactor(root);
    // if balance factor is disturbed
    if (bf > 1 && key < root->left->data) // L-L rotation
        return rightrotate(root);
    if (bf < -1 && key > root->right->data) // R-R rotation
        return leftrotate(root);
    if (bf > 1 && key > root->left->data) // L-R rotation
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (bf < -1 && key < root->right->data) // R-L rotation
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root; // if balance factor isn't disturbed
}
void inorder(avl *root)
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
    avl *root = NULL;
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 2);
    int d;
    printf("Enter the element to be searched: ");
    scanf("%d", &d);
    search(root, d);
    root = delete (root, 5);
    root = delete (root, 7);
    root = delete (root, 6);
    printf("Inorder traversal of the constructed AVL tree is \n");
    inorder(root);
    return 0;
}