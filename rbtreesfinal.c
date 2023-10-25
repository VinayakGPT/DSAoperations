//Red-Black Tree

//0->Black  1->Red

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *parent;
    int colour;
    struct node *right;
}*root=NULL;

void inOrder(struct node*p)
{
    if (p!=NULL)
    {
        inOrder(p->left);
        printf("%d\t",p->data);
        inOrder(p->right);
    }
}

void preOrder(struct node *p)
{
    if (p!=NULL)
    {
        printf("%d\t",p->data);
        preOrder(p->left);
        preOrder(p->right);
    }
}

struct node *createNode(int val)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->colour=1;
    newnode->left=newnode->right=newnode->parent=NULL;
    return newnode;
}

struct node *insert(struct node *root,struct node *temp)
{
    if(root==NULL)
        return temp;
    else if (root->data < temp->data)
    {
        root->right=insert(root->right,temp);
        root->right->parent=root;
    }
    else if (root->data > temp->data)
    {
        root->left=insert(root->left,temp);
        root->left->parent=root;
    }
    return root;
}

void rightRotate(struct node *gp)
{
    struct node *p=gp->left;
    struct node *c=p->right;
    p->right=gp;
    gp->left=c;
    if (c) 
        c->parent=gp;
    p->parent=gp->parent;
    if(gp==root)
        root=p;
    else if (gp->parent->left==gp)
        gp->parent->left=p;
    else
        gp->parent->right=p;
    gp->parent=p;
}

void leftRotate(struct node *gp)
{
    struct node *p=gp->right;
    struct node *c=p->left;
    p->left=gp;
    gp->right=c;
    if (c)
        c->parent=gp;
    p->parent=gp->parent;
    if(gp==root)
        root=p;
    else if (gp->parent->left==gp)
        gp->parent->left=p;
    else
        gp->parent->right=p;
    gp->parent=p;
}


void fixUp(struct node *root, struct node *temp)
{
    struct node *p=NULL;    //Parent
    struct node *gp=NULL;   //Grandparent
    struct node *uncle=NULL;    //Uncle

    while (temp!=root && temp->colour!=0 && temp->parent->colour==1)
    {
        p=temp->parent;
        gp=p->parent;
        if (p==gp->left)
        {
            uncle=gp->right;
            if(uncle!=NULL && uncle->colour==1)
            {
                uncle->colour=0;
                p->colour=0;
                gp->colour=1;
                temp=gp;
            }
            else
            {
                if(temp==p->right)
                {
                    leftRotate(p);
                    temp=p;
                    p=temp->parent;
                }
                rightRotate(gp);
                int t=p->colour;
                p->colour=gp->colour;
                gp->colour=t;
                temp=p;
            }
        }
        else
        {
            uncle=gp->left;
            if (uncle!=NULL && uncle->colour==1)
            {
                uncle->colour=0;
                p->colour=0;
                gp->colour=1;
                temp=gp;
            }
            else
            {
                if (p->left==temp)
                {
                    rightRotate(p);
                    temp=p;
                    gp=temp->parent;
                }
                leftRotate(gp);
                int t=p->colour;
                p->colour=gp->colour;
                gp->colour=t;
                temp=p;
            }
        }
    }

}

int main()
{
    int n = 7;
	int a[7] = {1,2,3,4,5,6,7};

	for (int i = 0; i < n; i++)
    {

		struct node* temp = createNode(a[i]);
		root = insert(root, temp);
		fixUp(root, temp);
        root->colour=0;
	}
    // inOrder(root);
    preOrder(root);
    return 0;
}