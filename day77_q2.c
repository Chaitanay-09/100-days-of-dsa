#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

// Adjacency list
int head[MAXN], nxt[MAXN * 2], to[MAXN * 2], cnt;
int disc[MAXN], low[MAXN], timer_val;
int visited[MAXN];

// Result storage
int res[MAXN][2], res_size;

void add_edge(int u, int v) {
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = timer_val++;

    for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = to[i];

        if (!visited[v]) {
            dfs(v, u);
            // Pull up the lowest reachable from child
            if (low[v] < low[u]) low[u] = low[v];

            // Bridge condition
            if (low[v] > disc[u]) {
                res[res_size][0] = u;
                res[res_size][1] = v;
                res_size++;
            }
        } else if (v != parent) {
            // Back edge — update low
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize,
                          int* connectionsColSize, int* returnSize,
                          int** returnColumnSizes) {
    // Init
    memset(head, -1, sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
    cnt = 0; timer_val = 0; res_size = 0;

    // Build undirected graph
    for (int i = 0; i < connectionsSize; i++) {
        add_edge(connections[i][0], connections[i][1]);
        add_edge(connections[i][1], connections[i][0]);
    }

    // DFS from node 0
    dfs(0, -1);

    // Build return array
    int** result = (int**)malloc(res_size * sizeof(int*));
    *returnColumnSizes = (int*)malloc(res_size * sizeof(int));
    for (int i = 0; i < res_size; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        result[i][0] = res[i][0];
        result[i][1] = res[i][1];
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = res_size;
    return result;
}