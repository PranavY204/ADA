#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 9999
struct Edge {
    int u, v, weight;
};
int compare(const void *a, const void *b) {
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight - b1->weight;
}
int find(int parent[], int i) {
    if (parent[i] == 0)
        return i;
    return find(parent, parent[i]);
}
void unionSets(int parent[], int u, int v) {
    parent[v] = u;
}
void kruskals(int cost_matrix[][MAX], int n) {
    struct Edge edges[MAX * MAX];
    int edge_count = 0;
    int parent[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost_matrix[i][j] != INF) {
                edges[edge_count++] = (struct Edge){i, j, cost_matrix[i][j]};
            }
        }
    }
    qsort(edges, edge_count, sizeof(edges[0]), compare);
    int mincost = 0;
    int ne = 0;
    printf("Edges in the Minimum Cost Spanning Tree:\n");
    for (int i = 0; i < edge_count; i++) {
        int u = find(parent, edges[i].u);
        int v = find(parent, edges[i].v);
        if (u != v) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].weight);
            unionSets(parent, u, v);
            mincost += edges[i].weight;
            ne++;
        }
        if (ne == n - 1)
            break;
    }
    printf("Minimum Cost of Spanning Tree: %d\n", mincost);
}
int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int cost_matrix[MAX][MAX];
    printf("Enter the cost matrix (n x n):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost_matrix[i][j]);
            if (cost_matrix[i][j] == 0 || cost_matrix[i][j] == -1)
                cost_matrix[i][j] = INF;
        }
    }
    kruskals(cost_matrix, n);
    return 0;
}
