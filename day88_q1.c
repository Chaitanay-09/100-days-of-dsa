#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with minimum distance = minDist
int canPlace(int* stalls, int n, int k, int minDist) {
    int count = 1;           // Place first cow at stalls[0]
    int lastPlaced = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPlaced >= minDist) {
            count++;                  // Place cow here
            lastPlaced = stalls[i];
            if (count == k) return 1; // All cows placed
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &stalls[i]);

    // Sort stall positions
    qsort(stalls, n, sizeof(int), cmp);

    // Binary search on answer: range [1, max - min]
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, k, mid)) {
            result = mid;       // mid works, try larger distance
            low = mid + 1;
        } else {
            high = mid - 1;     // too large, try smaller
        }
    }

    printf("%d\n", result);
    return 0;
}