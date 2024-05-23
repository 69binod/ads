// graph traversal using BFS
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES];

void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int start, int num_vertices)
{
    bool visited[MAX_VERTICES] = {false};

    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    queue[++rear] = start;
    visited[start] = true;

    while (front <= rear)
    {
        int vis = queue[front++];

        printf("%d ", vis);

        for (int i = 0; i < num_vertices; i++)
        {
            if (adj[vis][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int num_vertices, num_edges;
    int start_vertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges (u v) one by one:\n");
    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start_vertex);

    printf("BFS starting from vertex %d: ", start_vertex);
    bfs(start_vertex, num_vertices);
    printf("\n");

    return 0;
}