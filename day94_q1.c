#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(int *arr, int n, int *output) {
    if (n <= 0) return;

    // Find maximum value
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    // Build frequency array
    int *count = calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Compute prefix sums
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build output array (traverse right-to-left for stability)
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    free(count);
}

int main(void) {
    int arr[] = {4, 2, 7, 1, 9, 0, 3, 5, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int output[n];

    printf("Input:  ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    counting_sort(arr, n, output);

    printf("\nSorted: ");
    for (int i = 0; i < n; i++) printf("%d ", output[i]);
    printf("\n");

    return 0;
}