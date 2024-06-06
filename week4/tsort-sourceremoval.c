#include <stdio.h>

#define MAX_VERTICES 100

int indegree[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];

void topologicalSort(int V) {
    int queue[MAX_VERTICES], front = 0, rear = -1;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[++rear] = i;

    while (front <= rear) {
        int vertex = queue[front++];

        printf("%d ", vertex);

        for (int i = 0; i < V; i++)
            if (graph[vertex][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[++rear] = i;
            }
    }
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++)
            indegree[i] += graph[j][i];
    }

    printf("Topological Sort: ");
    topologicalSort(V);

    return 0;
}
