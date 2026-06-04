#include <stdio.h>
#include <stdlib.h>

// Depth-first search helper
void dfs(int** isConnected, int n, int city, int* visited) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, i, visited);
        }
    }
}

// Main function required by LeetCode
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int* visited = (int*)calloc(isConnectedSize, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < isConnectedSize; i++) {
        if (!visited[i]) {
            dfs(isConnected, isConnectedSize, i, visited);
            provinces++;
        }
    }

    free(visited);
    return provinces;
}
