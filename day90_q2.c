int splitArray(int* nums, int numsSize, int k) {
    long long low = 0, high = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > low) low = nums[i]; // max element
        high += nums[i];                   // sum of all
    }

    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Check if k subarrays can fit within max sum = mid
        int splits = 1;
        long long current = 0;

        for (int i = 0; i < numsSize; i++) {
            if (current + nums[i] <= mid) {
                current += nums[i];
            } else {
                splits++;
                current = nums[i];
                if (splits > k) break;
            }
        }

        if (splits <= k) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)result;
}