#include <stdio.h>
#include <stdlib.h>


int ** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
void backtrack(int **result, int *resultNum, int *nums, int numsSize, int leftIndex, int rightIndex);
void swap(int *nums, int a, int b);

int
main(int argc, char *argv[])
{
    int nums[3] = {1, 2, 3};
    int **result, returnSize, *returnColumnSizes;

    result = permute(nums, 3, &returnSize, &returnColumnSizes);

    printf("[");
    for(int i = 0; i < returnSize; ++i)
    {
        printf("[");
        printf("%d", result[i][0]);
        for(int j = 1; j < returnColumnSizes[i]; ++j)
        {
            printf(",%d", result[i][j]);
        }
        printf("]");
    }
    printf("]\n");
}

int**
permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **result;

    // Calculate the returnSize
    *returnSize = 1;
    for(int i = 2; i <= numsSize; ++i)
    {
        *returnSize *= i;
    }

    // malloc and fill columnSizes array
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    for(int i = 0; i < *returnSize; ++i)
    {
        (*returnColumnSizes)[i] = numsSize;
    }

    // malloc result array
    result = (int **)malloc(*returnSize * sizeof(int *));
    for(int i = 0; i < *returnSize; ++i)
    {
        result[i] = (int *)malloc(numsSize * sizeof(int));
    }

    // fill result array
    int resultNum = 0;
    backtrack(result, &resultNum, nums, numsSize, 0, numsSize - 1);

    return result;
}

void
backtrack(int **result, int *resultNum, int *nums, int numsSize, int leftIndex, int rightIndex)
{
    if(leftIndex == rightIndex)
    {
        for(int i = 0; i < numsSize; ++i)
        {
            result[*resultNum][i] = nums[i];
        }
        *resultNum += 1;
    }

    for(int i = leftIndex; i <= rightIndex; ++i)
    {
        swap(nums, leftIndex, i);
        backtrack(result, resultNum, nums, numsSize, leftIndex + 1, rightIndex);
        swap(nums, leftIndex, i);
    }
}

void
swap(int *nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
