#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                                  + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    printf("Items used: ");
    int c = W, res = K[n][W];
    for(int i = n; i > 0 && res > 0; i--){
        if (res == K[i-1][c]) continue;
        else {
            printf("(%d, %d)", wt[i-1], val[i-1]);
            res -= val[i-1];
            c -= wt[i-1];
        }
    }

    return K[n][W];
}

// Driver code
int main()
{

    int n, W; // W = 5
    printf("Enter no. of items: ");
    scanf("%d", &n);
    int profit[n], weight[n]; // weight: {1, 2, 1, 3}, profit: {10, 7 ,11, 15}
    printf("Enter weight of each item: ");
    for(int i = 0; i < n; i++) scanf("%d", &weight[i]);
    printf("Enter profit of each item: ");
    for(int i = 0; i < n; i++) scanf("%d", &profit[i]);
    fflush(stdin);
    printf("Enter max weight: ");
    scanf("%d", &W);
    printf("\nMax profit: %d", knapSack(W, weight, profit, n));

    return 0;
}
