#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int comp(const void *a, const void *b)
{
    int c = **(int **)a;
    int d = **(int **)b;

    return c - d;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    int **answer = intervals;
    int answer_size = intervalsSize;
    int *temp;

    qsort((void *)intervals, intervalsSize, sizeof(int *), comp);

    temp = intervals[0];
    for(int i = 1; i < intervalsSize; ++i)
    {
        if(temp[1] >= intervals[i][0])
        {
            --answer_size;
            temp[1] = temp[1] > intervals[i][1] ? temp[1] : intervals[i][1];

            free(intervals[i]);
            intervals[i] = NULL;
        }
        else
        {
            temp = intervals[i];
            if(intervalsSize - answer_size)
            {
                assert(intervals[i-intervalsSize+answer_size] == NULL);
                intervals[i-intervalsSize+answer_size] = intervals[i];
                intervals[i] = NULL;
            }
        }
    }

    *returnSize = answer_size;
    *returnColumnSizes = (int *)malloc(answer_size * sizeof(int));
    for(int i = 0; i < answer_size; ++i)
    {
        (*returnColumnSizes)[i] = 2;
    }

    return answer;
}

int main()
{
    int **intervals;
    int intervalsSize = 4;
    int returnSize;
    int *returnColumnSizes;
    int **answer;

    intervals = (int **)malloc(intervalsSize * sizeof(int *));
    for(int i = 0; i < intervalsSize; ++i)
    {
        intervals[i] = (int *)malloc(2 * sizeof(int));
    }

    intervals[0][0] = 1;
    intervals[0][1] = 3;
    intervals[1][0] = 2;
    intervals[1][1] = 6;
    intervals[2][0] = 8;
    intervals[2][1] = 10;
    intervals[3][0] = 15;
    intervals[3][1] = 18;

    answer = merge(intervals, intervalsSize, NULL, &returnSize, &returnColumnSizes);

    printf("[[%d, %d]", answer[0][0], answer[0][1]);
    for(int i = 1; i < returnSize; ++i)
    {
        printf(", [%d, %d]", answer[i][0], answer[i][1]);
    }
    printf("]\n");

    return 0;
}
