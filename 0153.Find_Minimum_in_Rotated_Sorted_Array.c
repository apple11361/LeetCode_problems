#include <stdio.h>
#include <stdbool.h>

int findMin(int* nums, int numsSize)
{
    int left, mid, right;

    left = 0;
    right = numsSize - 1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(nums[mid] < nums[right])
        {
            right = mid;
        }
        else if(nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right--;
        }
    }

    return nums[left];
}

int main()
{
    int nums[7] = {4, 5, 6, 0, 1, 2, 3};
    int numsSize = 7;
    int answer;

    answer = findMin(nums, numsSize);

    printf("answer: %d\n", answer);

    return 0;
}
