#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];

// Queue
int queue[MAX];
int front = 0, rear = 0;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    indegree[v]++; // increase indegree
}

// Kahn's Algorithm
void topologicalSort(int V) {
    int count = 0;

    // Push all nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Order:\n");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];
        while (temp != NULL) {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }

    // If count != V → cycle exists
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int V = 6;

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    // Example DAG
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(V);

    return 0;
}