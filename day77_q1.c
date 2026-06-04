#include <stdio.h>
#include <string.h>

#define MAXN 1005

int adj[MAXN][MAXN];
int visited[MAXN];
int n, m;

void bfs(int start) {
    int queue[MAXN];
    int front = 0, rear = 0;
    
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int node = queue[front++];
        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }
    
    // Start BFS from node 1
    bfs(1);
    
    // Check if all nodes were visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }
    
    printf("%s\n", connected ? "CONNECTED" : "NOT CONNECTED");
    
    return 0;
}