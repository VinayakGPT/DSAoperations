#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *push(struct node *head, int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}
int ispalindrome(struct node* head) {
    if (head == NULL) {
        return 1;
    }

    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    int arr[count];
    current = head;
    int i = 0;
    while (current != NULL) {
        arr[i] = current->data;
        i++;
        current = current->next;
    }

    int start = 0;
    int end = count - 1;
    while (start < end) {
        if (arr[start] != arr[end]) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}
int main()
{
    struct node *head = NULL;
    int value;
    printf("Create the linked list:\n");
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = push(head, value);
    }
    if (ispalindrome(head)) {
        printf("The linked list is palindromic.\n");
    } 
    else {
        printf("The linked list is not palindromic.\n");
    }
    return 0;
}