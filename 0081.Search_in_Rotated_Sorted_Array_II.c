#include <stdio.h>
#include <stdbool.h>

bool search(int *nums, int numsSize, int target)
{
    int left, mid, right;

    left = 0;
    right = numsSize - 1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(nums[mid] == target)
        {
            return true;
        }

        if(nums[mid] < nums[right])
        {
            if(nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else if(nums[mid] > nums[right])
        {
            if(nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            right--;
        }
    }

    return false;
}

int main()
{
    int nums[7] = {2, 5, 6, 0, 0, 1, 2};
    int numsSize = 7;
    int target = 0;
    bool answer;

    answer = search(nums, numsSize, target);

    if(answer)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
