#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    float coef;
    int exp;
    struct node *next;
} poly;
void displaypoly(poly *head)
{
    poly *ptr = head;
    printf("%.1fx^%d ", ptr->coef, ptr->exp);
    ptr = ptr->next;
    while (ptr != NULL)
    {
        if (ptr->exp == 1)
        {
            if (ptr->coef > 0)
                printf("+ %.1fx ", ptr->coef);
            else
                printf("- %.1fx ", -1 * ptr->coef);
        }
        else if (ptr->exp != 0)
        {
            if (ptr->coef > 0)
                printf("+ %.1fx^%d ", ptr->coef, ptr->exp);
            else
                printf("- %.1fx^%d ", -1 * ptr->coef, ptr->exp);
        }
        else
        {
            if (ptr->coef > 0)
                printf("+ %.1f ", ptr->coef);
            else
                printf("- %.1f ", -1 * ptr->coef);
        }
        ptr = ptr->next;
    }
    printf("\n");
}
poly *push(poly *head, int coef, int exp)
{
    poly *newnode = (poly *)malloc(sizeof(poly));
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->next = NULL;

    if (head == NULL || exp > head->exp)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        poly *temp = head;
        while (temp->next != NULL && temp->next->exp >= exp)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    return head;
}
poly *add(poly *poly1, poly *poly2)
{
    poly *poly3 = NULL;
    poly *temp1 = poly1;
    poly *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp == temp2->exp)
        {
            poly3 = push(poly3, temp1->coef + temp2->coef, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            poly3 = push(poly3, temp1->coef, temp1->exp);
            temp1 = temp1->next;
        }
        else
        {
            poly3 = push(poly3, temp2->coef, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        poly3 = push(poly3, temp1->coef, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        poly3 = push(poly3, temp2->coef, temp2->exp);
        temp2 = temp2->next;
    }

    return poly3;
}
poly *subtract(poly *poly1, poly *poly2)
{
    poly *poly3 = NULL;
    poly *temp1 = poly1;
    poly *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp == temp2->exp)
        {
            poly3 = push(poly3, temp1->coef - temp2->coef, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            poly3 = push(poly3, temp1->coef, temp1->exp);
            temp1 = temp1->next;
        }
        else
        {
            poly3 = push(poly3, temp2->coef, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        poly3 = push(poly3, temp1->coef, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        poly3 = push(poly3, temp2->coef, temp2->exp);
        temp2 = temp2->next;
    }

    return poly3;
}
poly *multiply(poly *poly1, poly *poly2)
{
    poly *poly3 = NULL;
    poly *temp1 = poly1;

    while (temp1 != NULL)
    {
        poly *temp2 = poly2;
        while (temp2 != NULL)
        {
            poly3 = push(poly3, temp1->coef * temp2->coef, temp1->exp + temp2->exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    poly *current = poly3;
    while (current != NULL && current->next != NULL) //both are reqd because this restricts access of current->next when current is the last node of the linked list.
    {
        if (current->exp == current->next->exp)
        {
            current->coef = current->coef + current->next->coef;
            poly *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        current = current->next;
    }
    return poly3;
}

int main()
{
    poly *poly1 = NULL;
    poly *poly2 = NULL;
    poly *result = NULL;
    float coef;
    int exp;
    int choice;

    do
    {
        printf("----- Polynomial Menu -----\n");
        printf("1. Enter coefficients and exponents for Polynomial 1\n");
        printf("2. Enter coefficients and exponents for Polynomial 2\n");
        printf("3. Add Polynomials\n");
        printf("4. Subtract Polynomials\n");
        printf("5. Multiply Polynomials\n");
        printf("6. Display Polynomial 1\n");
        printf("7. Display Polynomial 2\n");
        printf("8. Display Resultant Polynomial\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the coefficients and exponents of Polynomial 1 terms (Enter -1 -1 to stop):\n");
            while (1)
            {
                scanf("%f %d", &coef, &exp);
                if (coef == -1 && exp == -1)
                {
                    break;
                }
                poly1 = push(poly1, coef, exp);
            }
            break;

        case 2:
            printf("Enter the coefficients and exponents of Polynomial 2 terms (Enter -1 -1 to stop):\n");
            while (1)
            {
                scanf("%f %d", &coef, &exp);
                if (coef == -1 && exp == -1)
                {
                    break;
                }
                poly2 = push(poly2, coef, exp);
            }
            break;

        case 3:
            result = add(poly1, poly2);
            printf("Polynomials added.\n");
            break;

        case 4:
            result = subtract(poly1, poly2);
            printf("Polynomials subtracted.\n");
            break;

        case 5:
            result = multiply(poly1, poly2);
            printf("Polynomials multiplied.\n");
            break;

        case 6:
            printf("Polynomial 1: ");
            displaypoly(poly1);
            break;

        case 7:
            printf("Polynomial 2: ");
            displaypoly(poly2);
            break;

        case 8:
            printf("Resultant Polynomial: ");
            displaypoly(result);
            break;

        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}