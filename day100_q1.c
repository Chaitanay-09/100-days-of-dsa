#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ─── approach 1: merge sort ───────────────────────────────────────────────────

typedef struct { int val, idx; } Pair;

int *count;  // global result array

void mergeSort(Pair *arr, Pair *tmp, int left, int right) {
    if (right - left <= 1) return;

    int mid = (left + right) / 2;
    mergeSort(arr, tmp, left, mid);
    mergeSort(arr, tmp, mid, right);

    // Merge: count how many right-half elements are smaller than each left-half element
    int i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (arr[i].val <= arr[j].val) {
            // arr[j..right-1] elements already merged left are smaller
            count[arr[i].idx] += j - mid;
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    // Remaining left elements: all of right half (j to right) passed them
    while (i < mid) {
        count[arr[i].idx] += j - mid;
        tmp[k++] = arr[i++];
    }
    while (j < right) tmp[k++] = arr[j++];

    memcpy(arr + left, tmp + left, (right - left) * sizeof(Pair));
}

void countSmaller_mergeSort(int *nums, int n, int *result) {
    Pair *arr = malloc(n * sizeof(Pair));
    Pair *tmp = malloc(n * sizeof(Pair));
    count = result;

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
        result[i] = 0;
    }

    mergeSort(arr, tmp, 0, n);
    free(arr); free(tmp);
}

// ─── approach 2: fenwick tree (BIT) ──────────────────────────────────────────

int bit[20001];  // offset by 10000 to handle negatives [-10000, 10000]
int bitSize;

void update(int i) {
    for (i++; i <= bitSize; i += i & (-i))
        bit[i]++;
}

int query(int i) {
    int s = 0;
    for (i++; i > 0; i -= i & (-i))
        s += bit[i];
    return s;
}

void countSmaller_BIT(int *nums, int n, int *result) {
    int offset = 10000;     // shift negatives to positive indices
    bitSize = 20001;
    memset(bit, 0, sizeof(bit));

    // Traverse right to left
    for (int i = n - 1; i >= 0; i--) {
        int pos = nums[i] + offset;
        // Count elements already inserted that are smaller
        result[i] = (pos > 0) ? query(pos - 1) : 0;
        update(pos);
    }
}

// ─── driver ──────────────────────────────────────────────────────────────────

void printResult(int *nums, int *res, int n, const char *method) {
    printf("%s:\n  Input:  ", method);
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n  Output: ");
    for (int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("\n\n");
}

int main() {
    int nums[]  = {5, 2, 6, 1};
    int n = 4;
    int res1[4] = {0}, res2[4] = {0};

    countSmaller_mergeSort(nums, n, res1);
    printResult(nums, res1, n, "Merge Sort");

    countSmaller_BIT(nums, n, res2);
    printResult(nums, res2, n, "Fenwick Tree (BIT)");

    // Test 2
    int nums2[] = {-1, -1};
    int n2 = 2;
    int res3[2] = {0}, res4[2] = {0};

    countSmaller_mergeSort(nums2, n2, res3);
    printResult(nums2, res3, n2, "Merge Sort");

    countSmaller_BIT(nums2, n2, res4);
    printResult(nums2, res4, n2, "Fenwick Tree (BIT)");

    return 0;
}