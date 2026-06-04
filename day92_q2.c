#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findKthLargest(int* nums, int numsSize, int k) {
    srand(time(NULL));
    
    int left = 0, right = numsSize - 1;
    int target = numsSize - k;

    while (left <= right) {
        // random pivot
        int pivotIndex = left + rand() % (right - left + 1);
        int pivot = nums[pivotIndex];

        // 3-way partition
        int lt = left, i = left, gt = right;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(&nums[lt], &nums[i]);
                lt++; i++;
            } else if (nums[i] > pivot) {
                swap(&nums[i], &nums[gt]);
                gt--;
            } else {
                i++;
            }
        }

        if (target < lt) {
            right = lt - 1;
        } else if (target > gt) {
            left = gt + 1;
        } else {
            return nums[target];  // inside equal region
        }
    }

    return -1;
}