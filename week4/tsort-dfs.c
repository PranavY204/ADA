#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool visited[MAX_VERTICES];

void DFSUtil(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int* stack, int* top) {
    visited[vertex] = true;

    for (int i = 0; i < MAX_VERTICES; i++)
        if (graph[vertex][i] == 1 && !visited[i])
            DFSUtil(graph, i, stack, top);

    stack[*top - 1] = vertex;
    (*top)--;
}

void topologicalSort(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    bool visited[MAX_VERTICES];
    int stack[MAX_VERTICES];
    int top = V;

    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFSUtil(graph, i, stack, &top);

    printf("Topological Sort: ");
    while (top != V)
        printf("%d ", stack[top++]);
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V, &E);

    printf("Enter the adjacency matrix:\n");
    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    topologicalSort(graph, V);

    return 0;
}
