#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    int **answer, pow_n;
    int row_index, col_index;
    int direction; /*0: right, 1: down, 2: left, 3: up*/

    pow_n = n * n;

    answer= (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; ++i)
    {
        answer[i] = (int *)malloc(n * sizeof(int));
        memset(answer[i], 0, n * sizeof(int));
    }

    row_index = col_index = direction = 0;
    for(int i = 1; i <= pow_n; ++i)
    {
        answer[row_index][col_index] = i;

        // Choose the next position
        switch(direction)
        {
            case 0:
                if(col_index+1<n && answer[row_index][col_index+1] == 0)
                    ++col_index;
                else
                {
                    ++row_index;
                    ++direction;
                }
                break;
            case 1:
                if(row_index+1<n && answer[row_index+1][col_index] == 0)
                    ++row_index;
                else
                {
                    --col_index;
                    ++direction;
                }
                break;
            case 2:
                if(col_index-1>=0 && answer[row_index][col_index-1] == 0)
                    --col_index;
                else
                {
                    --row_index;
                    ++direction;
                }
                break;
            case 3:
                if(row_index-1>=0 && answer[row_index-1][col_index] == 0)
                    --row_index;
                else
                {
                    ++col_index;
                    direction = 0;
                }
                break;
        }

    }


    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i)
    {
        (*returnColumnSizes)[i] = n;
    }

    return answer;
}

int main()
{
    int n = 3;
    int returnSize, *returnColumnSizes, **answer;

    answer = generateMatrix(n, &returnSize, &returnColumnSizes);

    printf("[");
    for(int i = 0; i < n; ++i)
    {
        printf("[%d", answer[i][0]);
        for(int j = 1; j < n; ++j)
        {
            printf(", %d", answer[i][j]);
        }
        printf("]");
    }
    printf("]\n");

    return 0;
}
