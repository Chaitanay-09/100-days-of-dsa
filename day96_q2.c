#include <stdlib.h>

void mergeSort(int* nums, int* temp, int left, int right, int* count) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    
    mergeSort(nums, temp, left, mid, count);
    mergeSort(nums, temp, mid + 1, right, count);
    
    // Count reverse pairs BEFORE merging (both halves are sorted)
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        // nums[i] > 2 * nums[j], use long long to avoid overflow
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        *count += (j - (mid + 1));
    }
    
    // Standard merge
    int i = left, k = mid + 1, idx = left;
    while (i <= mid && k <= right) {
        if (nums[i] <= nums[k]) temp[idx++] = nums[i++];
        else temp[idx++] = nums[k++];
    }
    while (i <= mid) temp[idx++] = nums[i++];
    while (k <= right) temp[idx++] = nums[k++];
    
    for (int x = left; x <= right; x++) nums[x] = temp[x];
}

int reversePairs(int* nums, int numsSize) {
    int* temp = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    mergeSort(nums, temp, 0, numsSize - 1, &count);
    free(temp);
    return count;
}