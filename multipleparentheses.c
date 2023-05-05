#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int size;
    int top;
    char *arr;
} stack;
void pushelement(stack *s, char a)
{
    if (s->top == s->size - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = a;
}
char popelement(stack *s)
{
    char c;
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
        c = s->arr[s->top];
    s->top--;
    return c;
}
int isempty(stack *s)
{
    return (s->top == -1);
}
int match(char popped, char current)
{
    if (popped == '(' && current == ')')
        return 1;
    if (popped == '[' && current == ']')
        return 1;
    if (popped == '{' && current == '}')
        return 1;
    return 0;
}
int multiplematch(char *a)
{
    stack *temp=(stack*)malloc(sizeof(stack)); //before using pointer to structure, always allocate memory first.
    char popped;
    temp->size = 100;
    temp->top = -1;
    temp->arr = (char *)malloc(temp->size * sizeof(char));
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
            pushelement(temp, a[i]);
        else if (a[i] == ')' || a[i] == '}' || a[i] == ']')
        {
            if (isempty(temp))
                return 0;
            else
                popped = popelement(temp);
            if (!match(popped, a[i]))
                return 0;
        }
    }
    if (isempty(temp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char* exp;
    printf("Enter the expression you want to check: ");
    fgets(exp, 100000, stdin);
    if (multiplematch(exp))
    {
        printf("The parentheses are balanced");
    }
    else
    {
        printf("The parentheses are not balanced");
    }
    return 0;
}
