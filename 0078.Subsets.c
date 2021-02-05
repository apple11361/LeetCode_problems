#include <stdio.h>
#include <stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main(int argc, char *argv[])
{
    int nums[4] = {1, 2, 3, 4};
    int **result, returnSize, *returnColumnSizes;

    result = subsets(nums, 4, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; ++i)
    {
        for(int j = 0; j < returnColumnSizes[i]; ++j)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int retSize;
    int **answer, *retColSize;

    // Calculate the return size
    retSize = 1;
    retSize = retSize << numsSize;

    // Allocate space for answer
    answer = (int **)malloc(retSize * sizeof(int *));
    retColSize = (int *)malloc(retSize * sizeof(int));

    // Calculate the answer
    for(int i = 0; i < retSize; ++i)
    {
        // Calculate the size of this column
        int colSize;
        int iTemp;

        colSize = 0;
        iTemp = i;
        for(int j = 0; j < numsSize; ++j)
        {
            if(iTemp & 1)
            {
                ++colSize;
            }
            iTemp = iTemp >> 1;
        }
        retColSize[i] = colSize;

        //Calculate the answer
        answer[i] = (int *)malloc(colSize * sizeof(int));
        iTemp = i;

        for(int j = 0, k = 0; j < numsSize; ++j)
        {
            if(iTemp & 1)
            {
                answer[i][k++] = nums[j];
            }

            iTemp = iTemp >> 1;
        }
    }

    // Return the answer
    *returnSize = retSize;
    *returnColumnSizes = retColSize;
    return answer;
}

