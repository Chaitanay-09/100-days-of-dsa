#include <stdio.h>

int main() {
    int n, pos;

    // input size
    scanf("%d", &n);

    int arr[n];

    // input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // input position (1-based)
    scanf("%d", &pos);

    // shift elements left
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // print updated array
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
