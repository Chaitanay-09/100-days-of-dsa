int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int count[1001] = {0};

    // Step 1: Frequency count of arr1
    for (int i = 0; i < arr1Size; i++)
        count[arr1[i]]++;

    int* result = malloc(arr1Size * sizeof(int));
    int idx = 0;

    // Step 2: Place elements in arr2's relative order
    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]]-- > 0)
            result[idx++] = arr2[i];
    }

    // Step 3: Append remaining elements in ascending order
    for (int v = 0; v <= 1000; v++) {
        while (count[v]-- > 0)
            result[idx++] = v;
    }

    *returnSize = arr1Size;
    return result;
}