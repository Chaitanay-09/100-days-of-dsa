#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Greedy check: can we place m balls with at least minForce gap?
int canPlace(int* pos, int n, int m, int minForce) {
    int count = 1;
    int last = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - last >= minForce) {
            count++;
            last = pos[i];
            if (count == m) return 1;
        }
    }
    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    // Sort positions
    qsort(position, positionSize, sizeof(int), cmp);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            result = mid;       // feasible, try larger force
            low = mid + 1;
        } else {
            high = mid - 1;     // not feasible, reduce
        }
    }

    return result;
}