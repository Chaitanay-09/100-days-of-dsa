#include <stdio.h>

// ─────────────────────────────────────────────
//  Utility: swap two integers
// ─────────────────────────────────────────────
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// ─────────────────────────────────────────────
//  LOMUTO PARTITION
//  Pivot = last element
//  Returns final index of pivot
// ─────────────────────────────────────────────
int lomuto_partition(int arr[], int low, int high) {
    int pivot = arr[high];   // choose last element as pivot
    int i = low - 1;         // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);   // place pivot in correct spot
    return i + 1;
}

void quicksort_lomuto(int arr[], int low, int high) {
    if (low < high) {
        int pi = lomuto_partition(arr, low, high);
        quicksort_lomuto(arr, low, pi - 1);   // left of pivot
        quicksort_lomuto(arr, pi + 1, high);  // right of pivot
    }
}

// ─────────────────────────────────────────────
//  HOARE PARTITION
//  Pivot = first element
//  Returns index where left/right halves meet
// ─────────────────────────────────────────────
int hoare_partition(int arr[], int low, int high) {
    int pivot = arr[low];   // choose first element as pivot
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do { i++; } while (arr[i] < pivot);   // move right until ≥ pivot
        do { j--; } while (arr[j] > pivot);   // move left  until ≤ pivot

        if (i >= j) return j;                  // pointers crossed → done
        swap(&arr[i], &arr[j]);
    }
}

void quicksort_hoare(int arr[], int low, int high) {
    if (low < high) {
        int pi = hoare_partition(arr, low, high);
        quicksort_hoare(arr, low, pi);          // NOTE: pi, not pi-1
        quicksort_hoare(arr, pi + 1, high);
    }
}

// ─────────────────────────────────────────────
//  Utility: print array
// ─────────────────────────────────────────────
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ─────────────────────────────────────────────
//  Main
// ─────────────────────────────────────────────
int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int b[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original:        ");
    print_array(a, n);

    quicksort_lomuto(a, 0, n - 1);
    printf("Lomuto sorted:   ");
    print_array(a, n);

    quicksort_hoare(b, 0, n - 1);
    printf("Hoare sorted:    ");
    print_array(b, n);

    return 0;
}