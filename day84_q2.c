int findPeakElement(int* nums, int numsSize) {
    int lo = 0, hi = numsSize - 1;
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        
        if (nums[mid] > nums[mid + 1])
            hi = mid;        // peak is on the left half
        else
            lo = mid + 1;    // peak is on the right half
    }
    
    return lo;
}