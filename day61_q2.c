void dfs(int** isConnected, int n, int city, int* visited) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, i, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[n];
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, i, visited);
            provinces++;
        }
    }

    return provinces;
}