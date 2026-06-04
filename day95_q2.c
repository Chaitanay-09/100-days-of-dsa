#include <limits.h>
#include <stdlib.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    // Step 1: Find global min and max
    int gmin = INT_MAX, gmax = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < gmin) gmin = nums[i];
        if (nums[i] > gmax) gmax = nums[i];
    }

    // Edge case: all elements equal
    if (gmin == gmax) return 0;

    // Step 2: Setup n-1 buckets, each tracking min & max
    int n = numsSize;
    int *bmin = malloc(n * sizeof(int));
    int *bmax = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        bmin[i] = INT_MAX;   // unoccupied
        bmax[i] = INT_MIN;
    }

    // Step 3: Distribute elements into buckets
    // bucket width = (gmax - gmin) / (n - 1)
    for (int i = 0; i < n; i++) {
        if (nums[i] == gmax) continue;   // gmax goes to last slot separately
        int idx = (long long)(nums[i] - gmin) * (n - 1) / (gmax - gmin);
        if (nums[i] < bmin[idx]) bmin[idx] = nums[i];
        if (nums[i] > bmax[idx]) bmax[idx] = nums[i];
    }
    // gmax always anchors the last bucket
    bmin[n - 1] = bmax[n - 1] = gmax;

    // Step 4: Scan across bucket boundaries for max gap
    int maxGap = 0;
    int prevMax = gmin;        // right edge of previous occupied bucket

    for (int i = 0; i < n; i++) {
        if (bmin[i] == INT_MAX) continue;   // empty bucket — skip
        int gap = bmin[i] - prevMax;
        if (gap > maxGap) maxGap = gap;
        prevMax = bmax[i];
    }

    free(bmin);
    free(bmax);
    return maxGap;
}