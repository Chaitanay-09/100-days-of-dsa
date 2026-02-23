#include <stdio.h>

int main() {
    int n, k;

    scanf("%d", &n);

    int arr[n];

    // input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    // handle k greater than n
    k = k % n;

    // print rotated array
    for(int i = n-k; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for(int i = 0; i < n-k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
