#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Min-heap node
typedef struct {
    int node, dist;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size, capacity;
} MinHeap;

MinHeap* createHeap(int cap) {
    MinHeap* h = malloc(sizeof(MinHeap));
    h->data = malloc(cap * sizeof(HeapNode));
    h->size = 0;
    h->capacity = cap;
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a; *a = *b; *b = t;
}

void push(MinHeap* h, int node, int dist) {
    h->data[h->size++] = (HeapNode){node, dist};
    int i = h->size - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p].dist > h->data[i].dist) {
            swap(&h->data[p], &h->data[i]);
            i = p;
        } else break;
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode top = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if (l < h->size && h->data[l].dist < h->data[smallest].dist) smallest = l;
        if (r < h->size && h->data[r].dist < h->data[smallest].dist) smallest = r;
        if (smallest == i) break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
    return top;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    // Build adjacency list
    int** adj = calloc(n + 1, sizeof(int*));
    int* adjSize = calloc(n + 1, sizeof(int));
    int* adjCap = calloc(n + 1, sizeof(int));

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        if (adjSize[u] == adjCap[u]) {
            adjCap[u] = adjCap[u] ? adjCap[u] * 2 : 4;
            adj[u] = realloc(adj[u], adjCap[u] * 2 * sizeof(int));
        }
        adj[u][adjSize[u] * 2]     = times[i][1]; // neighbor
        adj[u][adjSize[u] * 2 + 1] = times[i][2]; // weight
        adjSize[u]++;
    }

    // Dijkstra
    int* dist = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) dist[i] = INT_MAX;
    dist[k] = 0;

    MinHeap* heap = createHeap(timesSize + 1);
    push(heap, k, 0);

    while (heap->size > 0) {
        HeapNode cur = pop(heap);
        int u = cur.node, d = cur.dist;

        if (d > dist[u]) continue; // stale entry

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i * 2];
            int w = adj[u][i * 2 + 1];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(heap, v, dist[v]);
            }
        }
    }

    // Find max dist across all nodes
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) return -1;
        if (dist[i] > ans) ans = dist[i];
    }

    // Cleanup
    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj); free(adjSize); free(adjCap);
    free(dist); free(heap->data); free(heap);

    return ans;
}