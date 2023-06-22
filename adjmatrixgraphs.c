#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void DFS(int start, int *visited, int **adj, int ver) // Double pointer to pass 2D array
{
    printf("%d ", start);
    visited[start] = 1;
    for (int j = 0; j < ver; j++)
    {
        if (adj[start][j] == 1 && !visited[j]) // If a vertex, from which an edge goes to an unvisited vertex, then make the recursive call.
        {
            DFS(j, visited, adj, ver);
        }
    }
}

int main()
{
    struct queue *q;
    q->size = 400;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    int ver;
    printf("Enter the number of vertices : ");
    scanf("%d", &ver);
    int a[ver];
    int adj[ver][ver];
    for (int i = 0; i < ver; i++)
        for (int j = 0; j < ver; j++)
            adj[i][j] = 0;
    for (int i = 0; i < ver; i++)
    {
        printf("Enter the vertices adjacent to vertex %d \n", i);
        int n;
        printf("Enter the number of neighbours of the vertex : ");
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            printf("Enter vertex : ");
            scanf("%d", &a[i]);
            adj[i][a[i]] = 1;
        }
    }
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    // BFS Implementation
    int node;
    int start;
    printf("Enter the vertex with which you want to start : ");
    scanf("%d", &start);
    int visited[ver];
    for (int i = 0; i < ver; i++)
        visited[i] = 0;
    printf("%d ", start);
    visited[start] = 1;
    enqueue(q, start); // Enqueue i for exploration
    while (!isEmpty(q))
    {
        int node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (adj[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }

    // DFS Implementation
    printf("Enter the vertex with which you want to start : ");
    scanf("%d", &start);
    DFS(start, visited, adj, ver);
    return 0;
}
