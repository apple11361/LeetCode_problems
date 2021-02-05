#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int *answer;
    int return_size;
    int row_size = matrixSize;
    int col_size = matrixColSize[0];
    int row_index, col_index;
    int direction; /*0: right, 1: down, 2: left, 3: up*/

    return_size = row_size * col_size;
    answer = (int *)malloc(return_size * sizeof(int));

    row_index = col_index = direction = 0;
    for(int i = 0; i < return_size; ++i)
    {
        answer[i] = matrix[row_index][col_index];
        matrix[row_index][col_index] = -101;

        // Check next position
        switch(direction)
        {
            case 0:
                if(col_index+1<col_size && matrix[row_index][col_index+1] != -101)
                    ++col_index;
                else
                {
                    ++row_index;
                    ++direction;
                }
                break;
            case 1:
                if(row_index+1<row_size && matrix[row_index+1][col_index] != -101)
                    ++row_index;
                else
                {
                    --col_index;
                    ++direction;
                }
                break;
            case 2:
                if(col_index-1>=0 && matrix[row_index][col_index-1] != -101)
                    --col_index;
                else
                {
                    --row_index;
                    ++direction;
                }
                break;
            case 3:
                if(row_index-1>=0 && matrix[row_index-1][col_index] != -101)
                    --row_index;
                else
                {
                    ++col_index;
                    direction = 0;
                }
                break;
        }
    }

    *returnSize = return_size;
    return answer;
}

int main()
{
    int **matrix;
    int matrixSize = 3;
    int matrixColSize[3] = {3, 3, 3};
    int *answer, returnSize;

    matrix = (int **)malloc(matrixSize * sizeof(int *));
    for(int i = 0; i < matrixSize; ++i)
    {
        matrix[i] = (int *)malloc(matrixColSize[i] * sizeof(int));
        for(int j = 0; j < matrixColSize[i]; ++j)
        {
            matrix[i][j] = i * matrixColSize[i] + j;
        }
    }

    answer = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);

    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", answer[i]);
    }

    return 0;
}
