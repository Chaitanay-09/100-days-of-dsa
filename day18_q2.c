#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* ans = (int*)malloc(numsSize * sizeof(int));

    // Step 1: left products
    ans[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        ans[i] = ans[i-1] * nums[i-1];
    }

    // Step 2: multiply with right products
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        ans[i] = ans[i] * right;
        right = right * nums[i];
    }

    return ans;
}
