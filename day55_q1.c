#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue implementation
Node* queue[1000];
int front = 0, rear = 0;

void enqueue(Node* node) {
    queue[rear++] = node;
}

Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Function to build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (!isEmpty() && i < n) {
        Node* current = dequeue();

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }
    return root;
}

// Function to print right view
void rightView(Node* root) {
    if (!root) return;

    front = rear = 0;
    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Node* temp = dequeue();

            // Print last node of level
            if (i == size - 1) {
                printf("%d ", temp->data);
            }

            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}