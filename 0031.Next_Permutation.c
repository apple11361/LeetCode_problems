#include <stdio.h>

void nextPermutation(int* nums, int numsSize)
{
    if(numsSize<2)
        return;

    int left_target = numsSize - 2;
    int right_target = numsSize - 1;
    int temp = nums[right_target];

    // Find the swap left target
    while(left_target >= 0 && nums[left_target] >= temp)
    {
        temp = nums[left_target];
        --left_target;
    }

    // Find the seap right target
    while(left_target >= 0 && nums[left_target] >= nums[right_target])
    {
        --right_target;
    }

    // Swap the targets
    printf("%d, %d\n", left_target, right_target);
    if(left_target >= 0)
    {
        nums[left_target] ^= nums[right_target];
        nums[right_target] ^= nums[left_target];
        nums[left_target] ^= nums[right_target];
    }

    // Reverse the numbers in the right side of left target
    for(int i = left_target+1; i < (left_target+1)+(numsSize-(left_target+1))/2; ++i)
    {
        nums[i] ^= nums[numsSize+left_target-i];
        nums[numsSize+left_target-i] ^= nums[i];
        nums[i] ^= nums[numsSize+left_target-i];
    }
}

int main()
{
    int nums[3] = {1, 5, 1};
    int numsSize = 3;

    nextPermutation(nums, numsSize);

    for(int i = 0; i < numsSize; ++i)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
