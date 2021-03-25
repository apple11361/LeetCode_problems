#include <stdio.h>

int findPeakElement(int *nums, int numsSize)
{
    int left, mid, right;

    left = 0;
    right = numsSize - 1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if((mid == 0 || nums[mid] > nums[mid-1]) && (mid == numsSize-1 || nums[mid] > nums[mid+1]))
        {
            return mid;
        }

        if(nums[mid] < nums[mid+1])
            left = mid + 1;
        else
            right = mid - 1;
    }

    return mid; // To avoid compile warnning
}

int main(int argc, char *argv[])
{
    int nums[4] = {1, 2, 3, 1};
    int numsSize = 4;
    int answer;

    answer = findPeakElement(nums, numsSize);

    printf("answer: %d\n", answer);

    return 0;
}
