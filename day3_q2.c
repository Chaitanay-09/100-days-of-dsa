int missingNum(int *arr, int size) {
    int n = size + 1;
    long long totalSum = (long long)n * (n + 1) / 2;
    long long arrSum = 0;

    for (int i = 0; i < size; i++) {
        arrSum += arr[i];
    }

    return (int)(totalSum - arrSum);
}