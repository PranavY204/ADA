#include <stdio.h>
#include <stdbool.h>

bool place(int[], int);
void printSolution(int[], int);
void nQueens(int);

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nQueens(n);
    return 0;
}

void nQueens(int n) {
    int x[10] = {0};  // Initialize the array to zero
    int count = 0;
    int k = 1;

    while (k != 0) {
        x[k] = x[k] + 1;

        while (x[k] <= n && !place(x, k)) {
            x[k] = x[k] + 1;
        }

        if (x[k] <= n) {
            if (k == n) {
                printSolution(x, n);
                printf("Solution found\n");
                count++;
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }

    printf("Total solutions: %d\n", count);
}

bool place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if ((x[i] == x[k]) || 
            (i - x[i] == k - x[k]) || 
            (i + x[i] == k + x[k])) {
            return false;
        }
    }
    return true;
}

void printSolution(int x[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}
