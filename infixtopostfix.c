#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack
{
    int size;
    int top;
    char *arr;
} stack;
int isfull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}
int isempty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
void push(stack *s, char c)
{
    if (isfull(s))
    {
        printf("Stack overflow. Stack is full!");
    }
    else
    {
        s->top++;
        s->arr[s->top] = c;
    }
}
char pop(stack *s)
{
    char popped;
    if (isempty(s))
        printf("Stack underflow. Stack is empty!");
    else
    {
        popped = s->arr[s->top];
        s->top--;
    }
    return popped;
}
char stacktop(stack *s)
{
    if (isempty(s))
        printf("Stack underflow. Stack is empty!");
    else
        return s->arr[s->top];
}
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
}
int isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return 1;
    else
        return 0;
}
char *infixtopostfix(char *infix)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // infix scanner
    int j = 0; // postfix fill
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i])) // this if statement will execute if the given function evaluates to false.
            postfix[j++] = infix[i++];
        else
        {
            if (isempty(s))
                push(s, infix[i++]);
            else if (precedence(infix[i]) > precedence(stacktop(s)))
                push(s, infix[i++]);
            else
                postfix[j++] = pop(s);
        }
    }
    while (!isempty(s))
        postfix[j++] = pop(s);
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = NULL;
    size_t size = 100000; //size_t is like a special tool that helps us measure and keep track of the sizes of things inside the computer's memory box.

    printf("Enter the infix expression you want to convert to postfix: ");
    infix = (char *)malloc(size * sizeof(char));

    if (infix == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    scanf("%s", infix); // In this programme, fgets() is not preferred to be used because then additional case of whitespaces would have to be added to the code, which will unnecessarily increase complexity.
    printf("Postfix is: %s\n", infixtopostfix(infix));
    free(infix);
    return 0;
}