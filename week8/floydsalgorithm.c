#include <stdio.h>
#include <limits.h>


int INF = 1e5;

void printSolution(int v, int dist[v][v]) {
    printf("The following matrix shows the shortest distances between every pair of vertices (-1 = infinity):\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}
// Function to implement Floyd Warshall algorithm
void floydWarshall(int v, int graph[v][v]) {
    int dist[v][v], i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices.
    for (k = 0; k < v; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < v; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < v; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(v, dist);
}



int main() {
    int v;
    printf("Enter no. of vertices: ");
    scanf("%d", &v);
    int graph[v][v];/* = { {0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0} }; */
    printf("Enter weighted adjacency matrix (Enter -1 for inf): \n");
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) graph[i][j] = INF;
        }
    }

    // Print the solution
    floydWarshall(v, graph);
    return 0;
}
