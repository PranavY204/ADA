void tsort(int mat[size][size], int n);

void tsortdfs(int mat[size][size], int n){
    bool visited[n];
    int stack[n], top=-1, poporder[n], pos=-1;
    for(int i = 0; i < n; i++) visited[i] = false;
    stack[++top] = 0;
    visited[0] = true;
    while(top != -1){
        bool new_node = false;
        for(int i = 0; i < n; i++){
            if(mat[stack[top]][i] == 1 && !visited[i]){
                new_node = true;
                stack[++top] = i;
                visited[i] = true;
                printf("%d\n", i);

                break;
            }
        }
        if (!new_node) poporder[++pos] = stack[top--];
    }
    // while(poporder != -1) printf("%d ", poporder[pos--]);
}

int main(){
    int n;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    int mat[size][size];
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    tsortdfs(mat, n);
}

void tsort(int mat[size][size], int n){
    int indegree[n];
    for(int i = 0; i < n; i++){
        indegree[i] =0;
        for(int j = 0; j < n; j++) indegree[i] += mat[j][i];
    }
    // for(int i = 0; i < n; i++) printf("Indegree of %d: %d\n", i, indegree[i]);
    int queue[n], sequence[n], front=0, rear=-1, counter=-1;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            queue[++rear] = i;
        }
    }
    // for(int i = 0; i < n; i++) printf("Queue[%d]: %d\n", i, queue[i]);
    printf("Topological Order: ");
    while(front<=rear){
        int u = queue[front++];
        printf("%d ", u+1);
        sequence[++counter] = u;
        // for(int i = 0; i < n; i++) printf("%d ", sequence[i]);
        for(int i = 0; i < n; i++){
            if(mat[u][i] == 1){
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[++rear] = i;
                // for(int i = 0; i < n; i++) printf("Indegree of %d: %d\n", i, indegree[i]);
            }

        }
    }
}
