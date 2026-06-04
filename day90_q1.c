/*
 * PAINTER'S PARTITION PROBLEM
 * Approach: Binary Search on Answer
 *
 * Key Insight:
 *   - Minimum possible time = max single board (1 painter per board)
 *   - Maximum possible time = sum of all boards (1 painter does all)
 *   - Binary search between these bounds
 *   - For each mid, check if k painters can finish in <= mid time
 */

#include <stdio.h>

/* Check if 'k' painters can paint all boards within 'max_time' */
int is_feasible(int *boards, int n, int k, long long max_time) {
    int painters_needed = 1;
    long long current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time + boards[i] <= max_time) {
            current_time += boards[i];
        } else {
            /* Assign a new painter for this board */
            painters_needed++;
            current_time = boards[i];

            if (painters_needed > k)
                return 0; /* Need more painters than available */
        }
    }
    return 1;
}

long long painters_partition(int *boards, int n, int k) {
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i]; /* max board length */
        high += boards[i];                     /* sum of all boards */
    }

    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (is_feasible(boards, n, k, mid)) {
            result = mid;   /* mid is feasible, try smaller */
            high = mid - 1;
        } else {
            low = mid + 1;  /* mid too small, try larger */
        }
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &boards[i]);

    printf("%lld\n", painters_partition(boards, n, k));
    return 0;
}