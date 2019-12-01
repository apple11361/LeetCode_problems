#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int i, j, k, temp;
    int **ans, ansSize;

    *returnSize = 0;
    ansSize = numsSize;

    ans = (int **)malloc(sizeof(int *) * ansSize);
    for (i = 0; i < ansSize; i++)
    {
        ans[i] = (int *)malloc(sizeof(int) * 3);
    }

    qsort(nums, numsSize, sizeof(int), comp);
    for (i = 0; i < numsSize - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) //skip repeated answer
            continue;

        j = i + 1;
        k = numsSize - 1;

        while (j < k)
        {
            temp = nums[i] + nums[j] + nums[k];
            if (temp > 0)
            {
                k--;
            }
            else if (temp < 0)
            {
                j++;
            }
            else
            {
                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[j];
                ans[*returnSize][2] = nums[k];
                *returnSize += 1;

                do
                {
                    j++;
                } while (j < k && nums[j] == nums[j - 1]);
                do
                {
                    k--;
                } while (j < k && nums[k] == nums[k + 1]);

                if (*returnSize == ansSize) //resize ans array
                {
                    ansSize <<= 2;
                    ans = (int **)realloc(ans, sizeof(int *) * ansSize);

                    for (int l = ansSize >> 2; l < ansSize; l++)
                    {
                        ans[l] = (int *)malloc(sizeof(int) * 3);
                    }
                }
            }
        }
    }

    /* output parameters */
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = 3;
    }

    return ans;
}

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize;
    int *returnColumnSizes;
    int **ans;

    ans = threeSum(nums, 6, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
