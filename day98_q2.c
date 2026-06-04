int cmp(const void *a, const void *b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Sort by start time
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    // Allocate result (worst case: no merges)
    int** result = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    int count = 0;

    // Initialize with first interval
    result[0] = malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[count][1]) {
            // Overlap → extend end if needed
            if (intervals[i][1] > result[count][1])
                result[count][1] = intervals[i][1];
        } else {
            // No overlap → new interval
            count++;
            result[count] = malloc(2 * sizeof(int));
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
        }
    }

    *returnSize = count + 1;
    return result;
}