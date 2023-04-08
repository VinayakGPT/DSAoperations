#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void linkedlisttraversal(struct node * head)
{
    struct node * ptr = head;
    do{
    printf("\nElement : %d",ptr->data);
    ptr=ptr->next;
    }while(ptr!=head);
}
void linkedlistinit(struct node * head)
{
    struct node * ptr = head;
    do{
    scanf("%d",&ptr->data);
    ptr=ptr->next;
    }while(ptr!=head);
}
struct node * insertfirst(struct node * head, int a)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=a;
    struct node * p=head->next;
    //here p is the pointer which supports traversal while ptr is the node which is to be inserted.
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
struct node * insertatindex(struct node * head, int a, int index)
{   
    struct node * p=(struct node *)malloc(sizeof(struct node *));
    struct node * ptr=head;
    int i=0;
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    }
    p->data=a;
    p->next=ptr->next;
    ptr->next=p;
    return head;
}
struct node * insertlast(struct node * head, int a)
{
    struct node * p=(struct node *)malloc(sizeof(struct node *));
    struct node * ptr=head;
    p->data=a;
    do
    {
        ptr=ptr->next;
    }while(ptr->next!=head);
    ptr->next=p;
    p->next=head;
    return head;
}
struct node * insertafternode(struct node * head, struct node * prevnode, int a)
{
    struct node * p=(struct node *)malloc(sizeof(struct node *));
    p->data=a;
    p->next=prevnode->next;
    prevnode->next=p;
    return head;
}
//commented code needs to be edited appropriately.
struct node * deletefirst(struct node * head)
{   
    if (head == NULL) {
        return NULL; // list is empty
    }
    if (head->next == head) {
        free(head); // list has only one element
        return NULL;
    }
    struct node * p = head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next = head->next;
    head = head->next;
    return head;
}
struct node * deleteatindex(struct node * head, int index)
{   
    struct node * ptr=head;
    struct node * p=head->next;
    int i=0;
    while(i!=index-1)
    {
    ptr=ptr->next;
    p=p->next;
    i++;
    }
    ptr->next=p->next;
    free(p);
    p=NULL;
    return head;
}
struct node * deletelast(struct node * head)
{   
    struct node * ptr=head;
    struct node * p=head->next;
    int i=0;
    while(p->next!=head){
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=head;
    free(p);
    p=NULL;
    return head;
}
struct node * deletevalue(struct node * head, int value)
{   
    struct node * ptr=head;
    struct node * p=head->next;
    if(head->data == value) { // delete the head node
        while(p->next != head) {
            p = p->next;
        }
        p->next = head->next;
        free(head);
        head = p->next;
    }
    else { // delete a non-head node
        while(p->data != value && p != head) {
            ptr = ptr->next;
            p = p->next;
        }
        if(p->data == value) {
            ptr->next = p->next;
            free(p);
            p = NULL;
        }
    }
    return head;
}
int main()
{
    int a;
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=head;
    linkedlistinit(head);
    linkedlisttraversal(head);
    head=deleteatindex(head,2);
    linkedlisttraversal(head);
    head=deletevalue(head,3);
    linkedlisttraversal(head);
    head=deletelast(head);
    linkedlisttraversal(head);
    head=insertfirst(head,12);
    linkedlisttraversal(head);
    head=deletefirst(head);
    linkedlisttraversal(head);
    printf("\nEnter the element you want to insert after second node");
    scanf("%d",&a);
    head=insertafternode(head,second,a);
    linkedlisttraversal(head);
    head=insertatindex(head,21,2);
    linkedlisttraversal(head);
    head=insertlast(head,5);
    linkedlisttraversal(head);
    return 0;
}