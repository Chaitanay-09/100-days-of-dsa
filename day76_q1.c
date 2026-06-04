#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

// Adjacency list using arrays
int head[MAXN], nxt[2 * MAXN], to[2 * MAXN], edge_cnt;
int visited[MAXN];
int stack[MAXN];

void add_edge(int u, int v) {
    edge_cnt++;
    to[edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt;
}

void dfs(int start) {
    int top = 0;
    stack[top++] = start;
    visited[start] = 1;

    while (top > 0) {
        int node = stack[--top];
        for (int e = head[node]; e != 0; e = nxt[e]) {
            int neighbor = to[e];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                stack[top++] = neighbor;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    memset(head, 0, sizeof(head));
    memset(visited, 0, sizeof(visited));
    edge_cnt = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}