// graph traversal using DFS
#include <stdio.h>
#include <stdlib.h>

int** adj;

void addEdge(int x, int y) {
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void dfs(int start, int* visited, int v) {
    printf("%d ", start);

    visited[start] = 1;

    for (int i = 0; i < v; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfs(i, visited, v);
        }
    }
}

int main() {
    int v, e;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    adj = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++) {
        adj[i] = (int*)malloc(v * sizeof(int));
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the edges (format: x y):\n");
    for (int i = 0; i < e; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(x, y);
    }

    int* visited = (int*)malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }

    printf("DFS starting from node 0:\n");
    dfs(0, visited, v);

    for (int i = 0; i < v; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);

    return 0;
}
