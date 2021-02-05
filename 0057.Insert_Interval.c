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
    answer = (int **)realloc(answer, answer_size * sizeof(int *));

    return answer;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{
    intervals = (int **)realloc(intervals, (intervalsSize+1) * sizeof(int *));
    intervals[intervalsSize] = (int *)malloc(2 * sizeof(int));

    intervals[intervalsSize][0] = newInterval[0];
    intervals[intervalsSize][1] = newInterval[1];

    return merge(intervals, intervalsSize+1, NULL, returnSize, returnColumnSizes);
}

int main()
{
    int **intervals;
    int *newInterval;
    int intervalsSize = 5;
    int returnSize;
    int *returnColumnSizes;
    int **answer;

    intervals = (int **)malloc(intervalsSize * sizeof(int *));
    newInterval = (int *)malloc(2 * sizeof(int));
    for(int i = 0; i < intervalsSize; ++i)
    {
        intervals[i] = (int *)malloc(2 * sizeof(int));
    }

    intervals[0][0] = 1;
    intervals[0][1] = 2;
    intervals[1][0] = 3;
    intervals[1][1] = 5;
    intervals[2][0] = 6;
    intervals[2][1] = 7;
    intervals[3][0] = 8;
    intervals[3][1] = 10;
    intervals[4][0] = 12;
    intervals[4][1] = 16;
    newInterval[0] = 4;
    newInterval[1] = 8;

    answer = insert(intervals, intervalsSize, NULL, newInterval, 2, &returnSize, &returnColumnSizes);

    printf("[[%d, %d]", answer[0][0], answer[0][1]);
    for(int i = 1; i < returnSize; ++i)
    {
        printf(", [%d, %d]", answer[i][0], answer[i][1]);
    }
    printf("]\n");

    return 0;
}
