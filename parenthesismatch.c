#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int top;
    char* arr;
} stack;

void pushelement(stack* s, char element) {
    if (s->top == s->size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = element;
}

void popelement(stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}

int isempty(stack* s) {
    return (s->top == -1);
}

int parenthesesmatch(char* a) {
    stack * temp;
    temp->size = 100;
    temp->top = -1;
    temp->arr = (char*)malloc(temp->size * sizeof(char));
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == '(')
            pushelement(temp, '(');
        else if (a[i] == ')') {
            if (isempty(temp))
                return 0;
            popelement(temp);
        }
    }
    if (isempty(temp))
        return 1;
    else
        return 0;
}

int main() {
    char* exp;
    printf("Enter the expression you want to check: ");
    fgets(exp, 100000, stdin);
    if (parenthesesmatch(exp)) {
        printf("The parentheses are matching.\n");
    } else {
        printf("The parentheses are not matching.\n");
    }
    free(exp);
    return 0;
}
