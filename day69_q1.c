#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for graph
typedef struct Graph {
    int V;
    Node* adj[MAX];
} Graph;

// Min Heap Node
typedef struct HeapNode {
    int vertex;
    int dist;
} HeapNode;

// Min Heap
typedef struct MinHeap {
    int size;
    HeapNode* nodes[MAX];
} MinHeap;

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

// Add edge
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// Create Min Heap
MinHeap* createMinHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}

// Swap heap nodes
void swap(HeapNode** a, HeapNode** b) {
    HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(MinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size &&
        heap->nodes[left]->dist < heap->nodes[smallest]->dist)
        smallest = left;

    if (right < heap->size &&
        heap->nodes[right]->dist < heap->nodes[smallest]->dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->nodes[i], &heap->nodes[smallest]);
        heapify(heap, smallest);
    }
}

// Extract min
HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;

    HeapNode* root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;

    heapify(heap, 0);
    return root;
}

// Insert into heap
void insertHeap(MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->nodes[i] = (HeapNode*)malloc(sizeof(HeapNode));
    heap->nodes[i]->vertex = v;
    heap->nodes[i]->dist = dist;

    while (i && heap->nodes[i]->dist < heap->nodes[(i - 1) / 2]->dist) {
        swap(&heap->nodes[i], &heap->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Dijkstra Algorithm
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    MinHeap* heap = createMinHeap();
    insertHeap(heap, src, 0);

    while (heap->size > 0) {
        HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print results
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Driver code
int main() {
    int V = 5;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);

    return 0;
}