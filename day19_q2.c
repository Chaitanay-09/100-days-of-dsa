int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    
    int currMax = nums[0], maxSum = nums[0];
    int currMin = nums[0], minSum = nums[0];
    
    for(int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
        
        if(i > 0) {
            // Kadane for maximum subarray
            currMax = (nums[i] > currMax + nums[i]) ? nums[i] : currMax + nums[i];
            maxSum = (maxSum > currMax) ? maxSum : currMax;
            
            // Kadane for minimum subarray
            currMin = (nums[i] < currMin + nums[i]) ? nums[i] : currMin + nums[i];
            minSum = (minSum < currMin) ? minSum : currMin;
        }
    }
    
    // If all elements are negative
    if(maxSum < 0)
        return maxSum;
    
    // Return maximum of normal and circular case
    return (maxSum > totalSum - minSum) ? maxSum : totalSum - minSum;
}
