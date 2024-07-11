#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
#define INF 9999
void dijkstra(int n, int src, int cost[MAX_NODES][MAX_NODES]);
int main() {
    int n;
    int cost[MAX_NODES][MAX_NODES];
    int src;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix (use -1 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == -1 && i != j) {
                cost[i][j] = INF;
            }
        }
    }
    printf("Enter the source node: ");
    scanf("%d", &src);
    dijkstra(n, src, cost);
    return 0;
}
void dijkstra(int n, int src, int cost[MAX_NODES][MAX_NODES]) {
    int dist[MAX_NODES];
    int vis[MAX_NODES];
    for (int j = 0; j < n; j++) {
        dist[j] = cost[src][j];
        vis[j] = 0;
    }
    dist[src] = 0;
    vis[src] = 1;
    int count = 1;
    while (count != n) {
        int min = INF;
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        vis[u] = 1;
        count++;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && cost[u][j] != INF && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }
    printf("Shortest distances from source node %d:\n", src);
    for (int j = 0; j < n; j++) {
        if (dist[j] == INF) {
            printf("To %d: Infinity\n", j);
        } else {
            printf("To %d: %d\n", j, dist[j]);
        }
    }
}
