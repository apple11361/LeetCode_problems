#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
    int index1 = 1;
    int index2 = 1;
    int repeat_num = 0;

    while(index2 < numsSize)
    {
        if(nums[index2] == nums[index2-1])
        {
            repeat_num++;
        }
        else
        {
            repeat_num = 0;
        }

        if(repeat_num < 2)
        {
            nums[index1++] = nums[index2];
        }

        index2++;
    }

    return index1;
}

int main()
{
    int nums[6] = {1, 1, 1, 2, 2, 3};
    int numsSize = 6;
    int answer;

    answer = removeDuplicates(nums, numsSize);

    for(int i = 0; i < answer; ++i)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
