typedef struct { int val, idx; } Pair;

Pair tmp_arr[100001];
int *cnt;

void mergeSort(Pair *arr, int left, int right) {
    if (right - left <= 1) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);

    int i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (arr[i].val <= arr[j].val) {
            cnt[arr[i].idx] += j - mid;
            tmp_arr[k++] = arr[i++];
        } else {
            tmp_arr[k++] = arr[j++];
        }
    }
    while (i < mid) {
        cnt[arr[i].idx] += j - mid;
        tmp_arr[k++] = arr[i++];
    }
    while (j < right) tmp_arr[k++] = arr[j++];

    for (int x = left; x < right; x++)
        arr[x] = tmp_arr[x];
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int *result = calloc(numsSize, sizeof(int));
    cnt = result;

    Pair *arr = malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, numsSize);

    free(arr);
    return result;
}