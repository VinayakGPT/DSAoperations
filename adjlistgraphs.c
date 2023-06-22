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

void DFS(struct node *adj[], int start, int visited[])
{
    visited[start] = 1;
    printf("%d ", start);
    struct node *ptr = adj[start];
    while (ptr != NULL)
    {
        if (visited[ptr->data] != 1)
            DFS(adj, ptr->data, visited);
        ptr = ptr->next;
    }
}

void BFS(struct node *adj[], int start, int visited[], int ver)
{
    int queue[ver], front = -1, rear = -1;
    struct node *ptr;
    queue[++rear] = start;
    front++;
    while (front <= rear)
    {
        start = queue[front++];
        ptr = adj[start];
        visited[start] = 1;
        printf("%d ", start);
        while (ptr != NULL)
        {
            if (visited[ptr->data] != 1)
            {
                queue[++rear] = ptr->data;
                visited[ptr->data] = 1;
            }
            ptr = ptr->next;
        }
    }
}

int main()
{
    int choice, ver, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &ver);

    struct node *heads[ver]; // array of heads
    int visited[ver];

    do
    {
        printf("\n----- Graph Menu -----\n");
        printf("1. Create Graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                for (int i = 0; i < ver; i++)
                {
                    int val;
                    struct node *head = NULL;

                    printf("Create the linked list for vertex %d:\n", i);
                    printf("Enter the number of elements: ");
                    int n;
                    scanf("%d", &n);

                    printf("Enter the elements:\n");
                    for (int j = 0; j < n; j++)
                    {
                        scanf("%d", &val);
                        head = push(head, val);
                    }

                    heads[i] = head;
                }
                break;
            }
            case 2:
            {
                printf("Enter the vertex with which you want to start: ");
                scanf("%d", &start);
                printf("BFS Traversal:\n");
                for (int i = 0; i < ver; i++)
                {
                    visited[i] = 0;
                }
                BFS(heads, start, visited, ver);
                break;
            }
            case 3:
            {
                printf("Enter the vertex with which you want to start: ");
                scanf("%d", &start);
                printf("DFS Traversal:\n");
                for (int i = 0; i < ver; i++)
                {
                    visited[i] = 0;
                }
                DFS(heads, start, visited);
                break;
            }
            case 0:
            {
                printf("Exiting the program...\n");
                break;
            }
            default:
            {
                printf("Invalid choice! Please enter a valid option.\n");
                break;
            }
        }
    } while (choice != 0);

    return 0;
}