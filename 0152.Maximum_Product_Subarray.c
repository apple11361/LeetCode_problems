#include <stdio.h>


int maxProduct(int *nums, int numsSize)
{
    int answer, min, max;

    answer = min = max = nums[0];

    for(int i = 1; i < numsSize; ++i)
    {
        if(nums[i] < 0)
        {
            min = min ^ max;
            max = min ^ max;
            min = min ^ max;
        }

        max = nums[i] > max*nums[i] ? nums[i] : max*nums[i];
        min = nums[i] < min*nums[i] ? nums[i] : min*nums[i];
        answer = max > answer ? max : answer;
    }

    return answer;
}

int main(int argc, char *argv[])
{
    int input[4] = {2, 3, -2, 4};
    int input2[3] = {-2, 0, -1};
    int answer;

    answer = maxProduct(input, 4);
    printf("answer: %d\n", answer);

    answer = maxProduct(input2, 3);
    printf("answer: %d\n", answer);

    return 0;
}
