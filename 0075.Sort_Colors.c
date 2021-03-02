#include <stdio.h>

void sortColors(int* nums, int numsSize)
{
    int whether_swap = 0;

    for(int i = 0; i < numsSize - 1; ++i)
    {
        for(int j = numsSize - 1; j > i; --j)
        {
            if(nums[j] < nums[j-1])
            {
                nums[j]   ^= nums[j-1];
                nums[j-1] ^= nums[j];
                nums[j]   ^= nums[j-1];

                whether_swap = 1;
            }
        }

        if(!whether_swap)
        {
            return;
        }

        whether_swap = 0;
    }
}

int main()
{
    int nums[6] = {2, 0, 2, 1, 1, 0};
    int numsSize = 6;

    sortColors(nums, numsSize);

    for(int i = 0; i < numsSize; ++i)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
