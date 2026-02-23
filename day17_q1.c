#include <stdio.h>

int main() {
    int n;

    // read size of array
    scanf("%d", &n);

    int arr[n];

    // read elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // assume first element is max and min
    int max = arr[0];
    int min = arr[0];

    // find max and min
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    // output
    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
