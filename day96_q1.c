#include <stdio.h>
#include <stdlib.h>

// ── Merge two halves and count split inversions ────────────────────────────────
long long merge_count(int *arr, int *tmp, int left, int mid, int right) {
    long long inv = 0;
    int i = left;    // pointer for left half
    int j = mid + 1; // pointer for right half
    int k = left;    // pointer for tmp

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            // arr[i..mid] are all > arr[j] (left half is sorted)
            // so all remaining left elements form inversions with arr[j]
            inv += (mid - i + 1);
            tmp[k++] = arr[j++];
        }
    }

    // Copy remaining elements
    while (i <= mid)  tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];

    // Copy back to original array
    for (int x = left; x <= right; x++)
        arr[x] = tmp[x];

    return inv;
}

// ── Recursive merge sort returning inversion count ────────────────────────────
long long merge_sort(int *arr, int *tmp, int left, int right) {
    if (left >= right) return 0;

    long long inv = 0;
    int mid = left + (right - left) / 2;

    inv += merge_sort(arr, tmp, left, mid);       // left half inversions
    inv += merge_sort(arr, tmp, mid + 1, right);  // right half inversions
    inv += merge_count(arr, tmp, left, mid, right); // split inversions

    return inv;
}

// ── Public interface ──────────────────────────────────────────────────────────
long long count_inversions(int *arr, int n) {
    int *tmp = malloc(n * sizeof(int));
    long long result = merge_sort(arr, tmp, 0, n - 1);
    free(tmp);
    return result;
}

// ── Helper: print array ───────────────────────────────────────────────────────
void print_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// ── Main ──────────────────────────────────────────────────────────────────────
int main(void) {
    int arr[] = {6, 3, 5, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input:      "); print_arr(arr, n);

    long long inv = count_inversions(arr, n);

    printf("Sorted:     "); print_arr(arr, n);
    printf("Inversions: %lld\n", inv);

    // ── Edge case tests ───────────────────────────────────────────────────────
    printf("\n── Edge Cases ──\n");

    int sorted[]  = {1, 2, 3, 4, 5};
    int rev[]     = {5, 4, 3, 2, 1};
    int single[]  = {42};
    int dupes[]   = {3, 1, 2, 3, 1};

    printf("Already sorted  %lld inversions (expected 0)\n",
           count_inversions(sorted, 5));
    printf("Fully reversed  %lld inversions (expected 10)\n",
           count_inversions(rev, 5));
    printf("Single element  %lld inversions (expected 0)\n",
           count_inversions(single, 1));
    printf("With duplicates %lld inversions (expected 4)\n",
           count_inversions(dupes, 5));

    return 0;
}