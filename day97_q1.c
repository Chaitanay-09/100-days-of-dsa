#include <stdio.h>
#include <stdlib.h>

// Min-heap for end times
typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap *h = malloc(sizeof(MinHeap));
    h->data = malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapifyUp(MinHeap *h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[parent] > h->data[i]) {
            swap(&h->data[parent], &h->data[i]);
            i = parent;
        } else break;
    }
}

void heapifyDown(MinHeap *h, int i) {
    while (1) {
        int smallest = i, l = 2*i+1, r = 2*i+2;
        if (l < h->size && h->data[l] < h->data[smallest]) smallest = l;
        if (r < h->size && h->data[r] < h->data[smallest]) smallest = r;
        if (smallest == i) break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
}

void push(MinHeap *h, int val) {
    h->data[h->size++] = val;
    heapifyUp(h, h->size - 1);
}

int pop(MinHeap *h) {
    int top = h->data[0];
    h->data[0] = h->data[--h->size];
    heapifyDown(h, 0);
    return top;
}

int peek(MinHeap *h) { return h->data[0]; }

// Comparator for sorting intervals by start time
int cmp(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int minMeetingRooms(int intervals[][2], int n) {
    if (n == 0) return 0;

    // Sort by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    MinHeap *heap = createHeap(n);
    push(heap, intervals[0][1]);  // push end time of first meeting

    for (int i = 1; i < n; i++) {
        // If earliest-ending meeting ends before this one starts, reuse room
        if (peek(heap) <= intervals[i][0])
            pop(heap);
        push(heap, intervals[i][1]);
    }

    int rooms = heap->size;
    free(heap->data);
    free(heap);
    return rooms;
}

int main() {
    int intervals[][2] = {{0,30},{5,10},{15,20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    printf("Meetings:\n");
    for (int i = 0; i < n; i++)
        printf("  [%d, %d]\n", intervals[i][0], intervals[i][1]);

    printf("Minimum rooms required: %d\n", minMeetingRooms(intervals, n));

    // Additional test
    int intervals2[][2] = {{7,10},{2,4}};
    int n2 = sizeof(intervals2) / sizeof(intervals2[0]);
    printf("\nMeetings:\n");
    for (int i = 0; i < n2; i++)
        printf("  [%d, %d]\n", intervals2[i][0], intervals2[i][1]);
    printf("Minimum rooms required: %d\n", minMeetingRooms(intervals2, n2));

    return 0;
}