#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void linkedlisttraversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("\nElement : %d",ptr->data);
        ptr=ptr->next;
    }
}
void linkedlistinit(struct node *ptr)
{
    while(ptr!=NULL)
    {
        scanf("%d",&ptr->data);
        ptr=ptr->next;
    }
}
struct node * insertfirst(struct node * ptr, int a)
{
    struct node * p=(struct node *)malloc(sizeof(struct node *));
    p->next=ptr;
    p->data=a;
    return p;
}
struct node * insertatindex(struct node * head, int a, int index)
{   
    struct node * p=(struct node *)malloc(sizeof(struct node *));
    struct node * ptr=head;
    /*In the given code, the variable head is a pointer to the first node of the linked list. It is used to keep track of the beginning of the linked list.The purpose of declaring the ptr variable is to traverse the linked list until the last node is reached. This is done by initializing ptr to head and then moving it to the next node until it reaches the end of the list. Therefore, ptr is used to keep track of the current position in the linked list while traversing it. Once the last node is reached, the new node p is added to the end of the list by setting the next pointer of the last node to p. Thus, ptr is necessary to iterate over the linked list and find the last node before adding the new node at the end of the list.*/
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
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=p;
    p->next=NULL;
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
struct node * deletefirst(struct node * head)
{   
    struct node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node * deleteatindex(struct node * head, int index)
{   
    struct node * ptr=head;
    struct node * p=head->next;
    int i=0;
    while(i!=index-1){
        ptr=ptr->next;
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    free(p);
    return head;
}
struct node * deletelast(struct node * head)
{   
    struct node * ptr=head;
    struct node * p=head->next;
    int i=0;
    while(p->next!=NULL){
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=NULL;
    free(p);
    return head;
}
struct node * deletevalue(struct node * head, int value)
{   
    struct node * ptr=head;
    struct node * p=head->next;
    while(p->data!=value&&p->next!=NULL){
        ptr=ptr->next;
        p=p->next;
    }
    if(p->data==value){
    ptr->next=p->next;
    free(p);
    }
    return head;
}
int main()
{
    int a,index;
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    struct node * fifth;
    struct node * sixth;
    /*allocate memory for nodes in heap*/
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    fifth=(struct node *)malloc(sizeof(struct node));
    sixth=(struct node *)malloc(sizeof(struct node));
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;
    linkedlistinit(head);
    linkedlisttraversal(head);
    printf("\nEnter the element you want to delete");
    scanf("%d",&a);
    head=deletevalue(head,a);
    linkedlisttraversal(head);
    printf("\nThe linked list after first element is deleted is :");
    head=deletefirst(head);
    linkedlisttraversal(head);
    printf("\nThe linked list after last element is deleted is :");
    head=deletelast(head);
    linkedlisttraversal(head);
    printf("\nEnter the index at which you want to delete element");
    scanf("%d",&index);
    head=deleteatindex(head,index);
    linkedlisttraversal(head);
    printf("\nEnter the element you want to insert after second node");
    scanf("%d",&a);
    head=insertafternode(head,second,a);
    linkedlisttraversal(head);
    printf("\nEnter the element you want to insert");
    scanf("%d",&a);
    head=insertlast(head,a);
    linkedlisttraversal(head);
    printf("\nEnter the element you want to insert");
    scanf("%d",&a);
    head=insertfirst(head,a);
    linkedlisttraversal(head);
    printf("\nEnter the index at which you wanna insert");
    scanf("%d",&index);
    printf("\nEnter the element you want to insert");
    scanf("%d",&a);    
    head=insertatindex(head,a,index);
    linkedlisttraversal(head);    
    return 0;
}