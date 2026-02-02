#include<stdio.h>
int main(){

    int i, j, nums[50], n, target;
    printf("Enter size of an array = ");
    scanf("%d", &n);

    printf("Enter the elements of an array = ");
    for(i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    printf("Enter the target element = ");
    scanf("%d", &target);

    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(nums[i] + nums[j] == target){
                printf("[%d, %d] ", i, j);
            }
        }
    }

    return 0;
}