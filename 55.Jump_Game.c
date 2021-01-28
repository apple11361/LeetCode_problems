#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize)
{
    int max = 0;

    for(int i = 0; i < numsSize; ++i)
    {
        if(i > max)
            return false;

        max = i + nums[i] > max ? i + nums[i] : max;
    }

    return true;
}

int main()
{
    int nums[5] = {3, 2, 1, 0, 4};
    int numsSize = 5;
    bool answer;

    answer = canJump(nums, numsSize);

    if(answer)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
