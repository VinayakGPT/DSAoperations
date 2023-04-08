#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * prev;
    struct node * next;
};
struct node * insertfirst(struct node * head, int a);
struct node * insertatindex(struct node * head, int index, int a);
struct node * insertlast(struct node * head, int a);
void revtraversal(struct node *head);
void initdll(struct node *head);
void revtraversal(struct node *head);
struct node * deletefirst(struct node * head);
struct node * deleteatindex(struct node * head, int index);
struct node * deletelast(struct node * head);
int main()
{
    int a, index;
    struct node * head=(struct node *)malloc(sizeof(struct node ));
    struct node * second=(struct node *)malloc(sizeof(struct node ));
    struct node * third=(struct node *)malloc(sizeof(struct node ));
    head->prev=NULL;
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=NULL;
    initdll(head);
    traversedll(head);
    revtraversal(head);
    printf("\nEnter the value that you want to insert at first : ");
    scanf("%d",&a);
    head=insertfirst(head,a);
    traversedll(head);
    printf("\nEnter the index at which you want to insert element : ");
    scanf("%d",&index);
    printf("\nEnter the element you want to insert");
    scanf("%d",&a);
    head=insertatindex(head,index,a);
    traversedll(head);
    printf("\nEnter the element you want to insert at last");
    scanf("%d",&a);
    head=insertlast(head,a);
    traversedll(head);
    head=deletefirst(head);
    traversedll(head);
    head=deletelast(head);
    traversedll(head);
    printf("\nEnter the index at which you want to delete element : ");
    scanf("%d",&index);
    head=deleteatindex(head,index);
    traversedll(head);
    return 0;
}
void initdll(struct node *head)
{
    int i=0;
    while(head!=NULL)
    {
        printf("Enter the data you want to input at index %d",i);
        scanf("%d",&head->data);
        head=head->next;
        i++;
    }
}
void traversedll(struct node *head)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node ));
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void revtraversal(struct node *head)
{
    struct node * ptr=malloc(sizeof(struct node ));
    ptr=head;
    while(ptr->next!=NULL) //this condition makes sure that we have reached the end of the linked list and that the code inside the loop body doesn't get executed. Therefore, when we are working with traversal, this will skip the last node of the linked list, but here, where we only have to reach the last node, it should be the condition. If not, code inside it will get executed, and the pointer will point to some other memory location which is not even a part of the linked list.
    {
        ptr=ptr->next;
    }
    do{
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
    while(ptr!=NULL);
    printf("\n");
}
struct node * insertfirst(struct node * head, int a)
{
    struct node * ptr=malloc(sizeof(struct node));
    ptr->data=a;
    ptr->prev=NULL;
    ptr->next=head;
    if(head != NULL)
    {
        head->prev=ptr;
    }
    return ptr;
}
struct node * insertatindex(struct node * head, int index, int a)
{
    struct node * ptr = head;
    struct node * p = malloc(sizeof(struct node));
    p->data = a;
    int i = 0;
    while (i != index - 1 && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    struct node * pt = ptr->next;
    p->next = pt;
    p->prev = ptr;
    if (pt != NULL) {
        pt->prev = p;
    }
    ptr->next = p;
    if (index == 0) {
        return p;
    }
    return head;
}
struct node * insertlast(struct node * head, int a)
{
    struct node * ptr=head;
    struct node * p=malloc(sizeof(struct node));
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    p->data=a;
    p->prev=ptr;
    ptr->next=p;
    p->next=NULL;
    return head;
}
struct node * deletefirst(struct node * head)
{
    struct node * ptr=head->next;
    head=ptr;
    head->next=ptr->next;
    head->prev=NULL;
    return head;
}
struct node * deleteatindex(struct node * head, int index)
{
    struct node *p=head;
    struct node *ptr=p->next;
    int i=0;
    while(i!=index-1 && p!=NULL)
    {
        p=p->next;
        ptr=ptr->next;
        i++;
    }
    if (p == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    struct node *pt=ptr->next;
    p->next=ptr->next;
    if(pt!=NULL){
    pt->prev=p;
    }
    free(ptr);
    return head;
}
struct node * deletelast(struct node * head)
{
    struct node * ptr=head;
    struct node * p=head->next;
    while(p->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    ptr->next=NULL;
    return head;
}