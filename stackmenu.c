#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;
typedef struct stackl
{
    int data;
    struct stackl *next;
} stackl;
int isempty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int isfull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}
void pushelement(stack *s, int val)
{
    if (isfull(s))
    {
        printf("Stack overflow. Cannot push %d in stack.", val);
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}
int popelement(stack *s)
{
    if (isempty(s))
    {
        printf("Stack underflow. The stack is empty!\n");
        return -1;
    }
    else
    {
        int temp = s->arr[s->top];
        s->top--;
        return temp;
    }
}
void displaystack(stack *s)
{
    if (isempty(s))
    {
        printf("Stack underflow. The stack is empty!\n");
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->arr[i]);
        }
    }
}
void peek(stack *s, int pos)
{
    if (s->top - pos + 1 < 0)
        printf("Invalid entry. No such position exists!\n");
    else if (isempty(s))
        printf("Stack underflow! Stack is empty.\n");
    else
        printf("The value at the given position is %d ", s->arr[s->top - pos + 1]);
}
void stacktop(stack *s)
{
    if (isempty(s))
        printf("Stack underflow! Stack is empty.\n");
    else
        printf("The element at the top is : %d ", s->arr[s->top]);
}
void stackbottom(stack *s)
{
    if (isempty(s))
        printf("Stack underflow! Stack is empty.\n");
    else
        printf("The element at the bottom is : %d ", s->arr[0]);
}
int isemptyl(stackl *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int isfulll(stackl *top)
{
    stackl *ptr = (stackl *)malloc(sizeof(stackl));
    if (ptr == NULL)
    {
        return 1;
    }
    else
        return 0;
}
stackl *pushl(stackl *top, int val)
{
    if (isfulll(top))
    {
        printf("Stack overflow! Stack is full.\n");
    }
    else
    {
        stackl *node = (stackl *)malloc(sizeof(stackl));
        node->data = val;
        node->next = top;
        top = node;
    }
    return top;
}
int popl(stackl **top)
{
    if (isemptyl(*top))
    {
        printf("Stack underflow. Stack is empty!\n");
        return -1;
    }
    else
    {
        stackl *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
void displaystackl(stackl *top)
{
    if (isemptyl(top))
        printf("Stack underflow. Stack is empty!\n");
    else
    {

        printf("Stack is : \n");
        while (top != NULL)
        {
            printf("%d\n", top->data);
            top = top->next;
        }
    }
}
void peekl(stackl *top, int pos)
{
    if (isemptyl(top))
        printf("Stack Underflow. Stack is empty!\n");
    else
    {
        stackl *temp = top;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if(temp==NULL)
        printf("Invalid entry. No such position exists!\n");
        else
        printf("The element at position %d is %d", pos, temp->data);
    }
}
void stackltop(stackl *top)
{
    if (isemptyl(top))
        printf("Stack underflow! Stack is empty.");
    else
        printf("The element at the top of the stack is %d", top->data);
}
void stacklbottom(stackl *top)
{
    if (isemptyl(top))
        printf("Stack underflow! Stack is empty.");
    else
    {
        stackl *temp = top;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("The element at the bottom of the stack is %d", temp->data);
    }
}
int main()
{
    int n, val, subsubchoice2, subsubchoice3, subsubchoice4, pos, size, popped;
    do
    {
        printf("\n----- Stack Menu -----\n");
        printf("1. Implement stack using Array.\n");
        printf("2. Implement stack using Linked List.\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &subsubchoice2);
        switch (subsubchoice2)
        {
        case 1:
            printf("Let's implement stack using array. \n");
            stack *s = (stack *)malloc(sizeof(stack)); // convenient to make a pointer of the structure because then it can be passed to functions and be called by reference.
            printf("Enter the size of stack : ");
            scanf("%d", &s->size);
            s->top = -1;
            s->arr = (int *)malloc(s->size * sizeof(int));
            printf("Enter the number of elements : ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter element : ");
                scanf("%d", &val);
                pushelement(s, val);
            }
            do
            {
                printf("\n----- Stack implemented using Array Menu -----\n");
                printf("1. Push element in stack\n");
                printf("2. Pop element in stack\n");
                printf("3. Display stack\n");
                printf("4. Peek element\n");
                printf("5. Display top element\n");
                printf("6. Display bottom element\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &subsubchoice3);

                switch (subsubchoice3)
                {
                case 1:
                    printf("Enter the value to push: ");
                    scanf("%d", &val);
                    pushelement(s, val);
                    break;
                case 2:
                    val = popelement(s);
                    if (val != -1)
                        printf("%d popped from the stack.\n", val);
                    break;
                case 3:
                    printf("Stack : \n");
                    displaystack(s);
                    break;
                case 4:
                    printf("Enter the position to peek: ");
                    scanf("%d", &pos);
                    peek(s, pos);
                    break;
                case 5:
                    stacktop(s);
                    break;
                case 6:
                    stackbottom(s);
                    break;
                case 0:
                    printf("Exiting the program.\n");
                    break;
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
                }
            } while (subsubchoice3 != 0);
            break;
        case 2:
            printf("Let's implement stack using linked list. \n");
            stackl *top = NULL;
            printf("Enter the number of elements : ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter element : ");
                scanf("%d", &val);
                top = pushl(top, val);
            }
            do
            {
                printf("\n----- Stack implemented using Linked List Menu -----\n");
                printf("1. Push element in stack\n");
                printf("2. Pop element in stack\n");
                printf("3. Display stack\n");
                printf("4. Peek element\n");
                printf("5. Display top element\n");
                printf("6. Display bottom element\n");
                printf("0. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &subsubchoice4);

                switch (subsubchoice4)
                {
                case 1:
                    printf("Enter the value to be pushed in stack : ");
                    scanf("%d", &val);
                    top = pushl(top, val);
                    printf("%d successfully pushed in stack.", val);
                    break;
                case 2:
                    popped = popl(&top);
                    if (popped != -1)
                        printf("%d popped successfully from stack.\n", popped);
                    break;
                case 3:
                    displaystackl(top);
                    break;
                case 4:
                    printf("Enter the position to peek: ");
                    scanf("%d", &pos);
                    peekl(top, pos);
                    break;
                case 5:
                    stackltop(top);
                    break;
                case 6:
                    stacklbottom(top);
                    break;
                case 0:
                    printf("Exiting the program.\n");
                    break;
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
                }
            } while (subsubchoice4 != 0);
        }
    } while (subsubchoice2 != 0);
    
    return 0;
}