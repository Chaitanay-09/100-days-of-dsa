struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;

    // visited array to store cloned nodes (val is 1-indexed, max 100)
    struct Node* visited[101] = {NULL};

    // BFS queue
    struct Node* queue[101];
    int front = 0, rear = 0;

    // Clone the starting node
    struct Node* cloneStart = (struct Node*)malloc(sizeof(struct Node));
    cloneStart->val = s->val;
    cloneStart->numNeighbors = s->numNeighbors;
    cloneStart->neighbors = (struct Node**)calloc(s->numNeighbors, sizeof(struct Node*));

    visited[s->val] = cloneStart;
    queue[rear++] = s;

    while (front < rear) {
        struct Node* curr = queue[front++];
        struct Node* currClone = visited[curr->val];

        for (int i = 0; i < curr->numNeighbors; i++) {
            struct Node* neighbor = curr->neighbors[i];

            if (!visited[neighbor->val]) {
                // Create clone of neighbor
                struct Node* neighborClone = (struct Node*)malloc(sizeof(struct Node));
                neighborClone->val = neighbor->val;
                neighborClone->numNeighbors = neighbor->numNeighbors;
                neighborClone->neighbors = (struct Node**)calloc(neighbor->numNeighbors, sizeof(struct Node*));

                visited[neighbor->val] = neighborClone;
                queue[rear++] = neighbor;  // visit original neighbor next
            }

            // Link clone to its cloned neighbor
            currClone->neighbors[i] = visited[neighbor->val];
        }
    }

    return cloneStart;
}struct Node* cloneGraph(struct Node* s) {
    if (!s) return NULL;

    // visited array to store cloned nodes (val is 1-indexed, max 100)
    struct Node* visited[101] = {NULL};

    // BFS queue
    struct Node* queue[101];
    int front = 0, rear = 0;

    // Clone the starting node
    struct Node* cloneStart = (struct Node*)malloc(sizeof(struct Node));
    cloneStart->val = s->val;
    cloneStart->numNeighbors = s->numNeighbors;
    cloneStart->neighbors = (struct Node**)calloc(s->numNeighbors, sizeof(struct Node*));

    visited[s->val] = cloneStart;
    queue[rear++] = s;

    while (front < rear) {
        struct Node* curr = queue[front++];
        struct Node* currClone = visited[curr->val];

        for (int i = 0; i < curr->numNeighbors; i++) {
            struct Node* neighbor = curr->neighbors[i];

            if (!visited[neighbor->val]) {
                // Create clone of neighbor
                struct Node* neighborClone = (struct Node*)malloc(sizeof(struct Node));
                neighborClone->val = neighbor->val;
                neighborClone->numNeighbors = neighbor->numNeighbors;
                neighborClone->neighbors = (struct Node**)calloc(neighbor->numNeighbors, sizeof(struct Node*));

                visited[neighbor->val] = neighborClone;
                queue[rear++] = neighbor;  // visit original neighbor next
            }

            // Link clone to its cloned neighbor
            currClone->neighbors[i] = visited[neighbor->val];
        }
    }

    return cloneStart;
}