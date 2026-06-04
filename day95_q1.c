#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ── Linked-list node for each bucket ──────────────────────────────────────────
typedef struct Node {
    float val;
    struct Node *next;
} Node;

// ── Insert into bucket keeping sorted order (insertion sort inline) ───────────
void bucket_insert(Node **head, float val) {
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    // Insert at head if empty or val is smallest
    if (!*head || val < (*head)->val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *cur = *head;
    while (cur->next && cur->next->val < val)
        cur = cur->next;

    newNode->next = cur->next;
    cur->next = newNode;
}

// ── Free all nodes in a bucket ────────────────────────────────────────────────
void bucket_free(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

// ── Bucket Sort ───────────────────────────────────────────────────────────────
void bucket_sort(float *arr, int n) {
    if (n <= 1) return;

    // Allocate n buckets (each covers range [i/n, (i+1)/n))
    Node **buckets = calloc(n, sizeof(Node *));

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);      // maps [0,1) → [0, n-1]
        if (idx >= n) idx = n - 1;        // safety clamp for val == 0.9999...
        bucket_insert(&buckets[idx], arr[i]);
    }

    // Concatenate sorted buckets back into arr
    int pos = 0;
    for (int i = 0; i < n; i++) {
        Node *cur = buckets[i];
        while (cur) {
            arr[pos++] = cur->val;
            cur = cur->next;
        }
        bucket_free(buckets[i]);
    }

    free(buckets);
}

// ── Helper: print array ───────────────────────────────────────────────────────
void print_arr(float *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%.4f ", arr[i]);
    printf("\n");
}

// ── Main ──────────────────────────────────────────────────────────────────────
int main(void) {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input:  "); print_arr(arr, n);
    bucket_sort(arr, n);
    printf("Sorted: "); print_arr(arr, n);

    return 0;
}