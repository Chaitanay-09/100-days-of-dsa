#include <stdio.h>
#include <limits.h>

#define MAXN 1005
#define MAXM 100005
#define INF INT_MAX

// Adjacency list using arrays
int head[MAXN], to[MAXM*2], wt[MAXM*2], nxt[MAXM*2], cnt;
int dist[MAXN], visited[MAXN];
int n, m;

void addEdge(int u, int v, int w) {
    to[++cnt] = v;
    wt[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

// Min-heap (priority queue)
typedef struct {
    int node, cost;
} Node;

Node heap[MAXM * 2];
int heapSize = 0;

void push(int node, int cost) {
    heap[++heapSize] = (Node){node, cost};
    int i = heapSize;
    while (i > 1 && heap[i].cost < heap[i/2].cost) {
        Node tmp = heap[i]; heap[i] = heap[i/2]; heap[i/2] = tmp;
        i /= 2;
    }
}

Node pop() {
    Node top = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int smallest = i, l = 2*i, r = 2*i+1;
        if (l <= heapSize && heap[l].cost < heap[smallest].cost) smallest = l;
        if (r <= heapSize && heap[r].cost < heap[smallest].cost) smallest = r;
        if (smallest == i) break;
        Node tmp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

void dijkstra(int src) {
    for (int i = 1; i <= n; i++) dist[i] = INF, visited[i] = 0;
    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        Node cur = pop();
        int u = cur.node;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int e = head[u]; e; e = nxt[e]) {
            int v = to[e], w = wt[e];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }
}

int main() {
    int src;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // undirected graph
    }

    scanf("%d", &src);
    dijkstra(src);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("INF");
        else
            printf("%d", dist[i]);
        if (i < n) printf(" ");
    }
    printf("\n");

    return 0;
}