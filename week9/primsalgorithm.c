#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX_VERTICES 100
#define INF INT_MAX
int minKey(int n, int d[], int s[]) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (s[v] == 0 && d[v] < min) {
            min = d[v];
            min_index = v;
        }
    }
    return min_index;
}
int printMST(int n, int p[], int cost[MAX_VERTICES][MAX_VERTICES]) {
    int total_cost = 0;
    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d    %d \n", p[i], i, cost[i][p[i]]);
        total_cost += cost[i][p[i]];
    }
    return total_cost;
}
int parseCost(int n, int cost[MAX_VERTICES][MAX_VERTICES]) {
    char input[10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", input);
            if (strcmp(input, "inf") == 0) {
                cost[i][j] = INF;
            } else {
                sscanf(input, "%d", &cost[i][j]);
                if (cost[i][j] == 0 && i != j) {
                    cost[i][j] = INF;
                }
            }
        }
    }
}
void primMST(int n, int cost[MAX_VERTICES][MAX_VERTICES]) {
    int p[MAX_VERTICES];
    int d[MAX_VERTICES];
    int s[MAX_VERTICES];
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        s[i] = 0;
    }
    d[0] = 0;
    p[0] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(n, d, s);
        s[u] = 1;
        for (int v = 0; v < n; v++) {
            if (cost[u][v] && s[v] == 0 && cost[u][v] < d[v]) {
                p[v] = u;
                d[v] = cost[u][v];
            }
        }
    }
    int total_cost = printMST(n, p, cost);
    printf("Total cost of Minimum Spanning Tree (MST): %d\n", total_cost);
}
int main() {
    
    /*                  { { 0, 2, 0, 6, 0},
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0                                                                                                                         } }; */
    int n;
    int cost[MAX_VERTICES][MAX_VERTICES];
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix (use 'inf' for infinity):\n");
    parseCost(n, cost);
    printf("Minimum Spanning Tree (MST) using Prim's algorithm:\n");
    primMST(n, cost);
    return 0;
}
