#include <stdio.h>

int singleNumber(int *nums, int numsSize)
{
    int once, twice, thrice;

    once = 0;
    twice = 0;
    thrice = 0;

    for(int i = 0; i < numsSize; ++i)
    {
        twice |= once & nums[i];
        once ^= nums[i];
        thrice = once & twice;
        twice &= ~thrice;
        once &= ~thrice;
    }
    return once;
}

int main(int argc, char *argv[])
{
    int nums[7] = {0, 1, 0, 1, 0, 1, 99};
    int answer;

    answer = singleNumber(nums, 7);

    printf("answer: %d\n", answer);

    return 0;
}
