#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * push(struct node * head, int val)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if (head == NULL) {
        head = newnode;
    }
    else{
        struct node * temp=head;
        while(temp->next!=NULL){
        temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
void printlist(struct node *head)
{
    struct node * ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void freelist(struct node* head) 
{
    struct node* temp = head;
    struct node* next;

    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
}
struct node * getmid(struct node * head)
{
    struct node * slow = head;
    struct node * fast = head;
    struct node * temp = NULL;
    while(fast!=NULL && fast->next!=NULL){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(temp!=NULL){
        temp->next=NULL;
    }
    return slow;
}
struct node * merge(struct node * left, struct node * right)
{
    struct node merged;
    struct node * mergeadd = &merged;
    while(left!=NULL && right!=NULL){
        if(left->data<=right->data)
        {
            mergeadd->next=left;
            left=left->next;
        }
        else{
            mergeadd->next=right;
            right=right->next;
        }
        mergeadd=mergeadd->next;
    }
    if (left != NULL) {
        mergeadd->next = left;
    } else {
        mergeadd->next = right;
    }
    return merged.next;
}
struct node * mergesort(struct node * head)
{
    if(head==NULL || head->next==NULL)
    return head;
    struct node * mid=getmid(head);
    struct node * left=mergesort(head);
    struct node * right=mergesort(mid);
    return merge(left,right);
}
int main()
{
    struct node * head=NULL;
    int n,val;
    printf("Enter the number of elements in the linked list : ");
    scanf("%d",&n);
    printf("Enter the elements :");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        head = push(head, val);
    }
    printf("Original list: ");
    printlist(head);
    head = mergesort(head);
    printf("\nSorted list: ");
    printlist(head);
    freelist(head); 
    return 0;
}