#include <stdio.h>
#include <limits.h>

#define MAXN 1005

int graph[MAXN][MAXN];
int key[MAXN];
int inMST[MAXN];
int n, m;

int minKey() {
    int min = INT_MAX, minIdx = -1;
    for (int v = 1; v <= n; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIdx = v;
        }
    }
    return minIdx;
}

int primMST() {
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[1] = 0;
    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey();
        if (u == -1) break;

        inMST[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", primMST());
    return 0;
}