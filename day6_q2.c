void moveZeroes(int* nums, int numsSize) {
    int pos = 0; 

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[pos++] = nums[i];
        }
    }

    while (pos < numsSize) {
        nums[pos++] = 0;
    }
}
