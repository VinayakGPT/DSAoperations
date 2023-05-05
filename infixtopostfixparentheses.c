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
int outprecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '^')
        return 6;
    else if (c == '(')
        return 7;
}
int isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' ||  c == '^')
        return 1;
    else
        return 0;
}
int inprecedence(char c)
{
    if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/')
        return 4;
    else if (c == '^')
        return 5;
    else if (c == '(')
        return 0;
}
char *infixtopostfix(char *infix)
{
    char popped;
    stack *s = (stack *)malloc(sizeof(stack));
    int i = 0;
    int j = 0;
    s->top = -1;
    s->size = 100;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        /* When a closing parenthesis is encountered, we pop operators from the stack and append them to the postfix expression until we reach the corresponding opening parenthesis. To do this, we enter a loop that continues until the stack is empty or the top of the stack contains an opening parenthesis. If the top of the stack is an opening parenthesis, we remove it from the stack. Finally, we increment the index i to skip the closing parenthesis. */
        if (infix[i] == '(')
        {
            push(s, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (!isempty(s) && s->arr[s->top] != '(')
            {
                popped = pop(s);
                postfix[j++] = popped;
            }

            if (!isempty(s) && s->arr[s->top] == '(')
                pop(s); // Pop the opening parenthesis from stack

            i++;
        }
        else if (isoperator(infix[i]))
        {
            if (isempty(s))
                push(s, infix[i++]);
            else
            {
                if (outprecedence(infix[i]) > inprecedence(s->arr[s->top]))
                    push(s, infix[i++]);
                else
                {
                    popped = pop(s);
                    postfix[j++] = popped;
                }
            }
        }
        else
        {
            postfix[j++] = infix[i++];
        }
    }

    while (!isempty(s))
    {
        popped = pop(s);
        postfix[j++] = popped;
    }

    postfix[j] = '\0'; // Terminate postfix string

    free(s->arr);
    free(s);

    return postfix;
}

int main()
{
    char *infix = NULL;
    size_t size = 100000; // size_t is like a special tool that helps us measure and keep track of the sizes of things inside the computer's memory box.

    printf("Enter the infix expression you want to convert to postfix: ");
    infix = (char *)malloc(size * sizeof(char));

    if (infix == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    scanf("%s", infix);
    char *postfix = NULL;
    postfix = (char *)malloc(size * sizeof(char));

    if (postfix == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    postfix = infixtopostfix(infix);
    printf("Postfix is: %s\n", postfix);
    free(infix);
    return 0;
}