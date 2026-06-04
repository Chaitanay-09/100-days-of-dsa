void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap with low partition
            int tmp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = tmp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            // 1 is in correct region, just advance
            mid++;
        } else {
            // Swap with high partition
            int tmp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = tmp;
            high--;
            // Don't advance mid — recheck swapped element
        }
    }
}