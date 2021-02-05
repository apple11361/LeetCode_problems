#include <stdio.h>
#include <stdlib.h>

void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    int row_size = matrixSize;
    int col_size = matrixColSize[0];
    int is_top_zero, is_left_zero;

    is_top_zero = is_left_zero = 0;

    for(int i = 0; i < row_size; ++i)
    {
        if(matrix[i][0] == 0)
        {
            is_left_zero = 1;
            break;
        }
    }
    for(int i = 0; i < col_size; ++i)
    {
        if(matrix[0][i] == 0)
        {
            is_top_zero = 1;
            break;
        }
    }

    for(int i = 1; i < row_size; ++i)
    {
        for(int j = 1; j < col_size; ++j)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < row_size; ++i)
    {
        for(int j = 1; j < col_size; ++j)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if(is_left_zero)
    {
        for(int i = 0; i < row_size; ++i)
        {
            matrix[i][0] = 0;
        }
    }
    if(is_top_zero)
    {
        for(int i = 0; i < col_size; ++i)
        {
            matrix[0][i] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    int **matrix;
    int matrixSize, matrixColSize;

    matrixSize = 3;
    matrixColSize = 4;

    matrix = (int **)malloc(matrixSize * sizeof(int *));
    for(int i = 0; i < matrixSize; ++i)
    {
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
    }

    matrix[0][0] = 0;
    matrix[0][1] = 1;
    matrix[0][2] = 2;
    matrix[0][3] = 0;
    matrix[1][0] = 3;
    matrix[1][1] = 4;
    matrix[1][2] = 5;
    matrix[1][3] = 2;
    matrix[2][0] = 1;
    matrix[2][1] = 3;
    matrix[2][2] = 1;
    matrix[2][3] = 5;

    setZeroes(matrix, matrixSize, &matrixColSize);

    printf("[");
    for(int i = 0; i < matrixSize; ++i)
    {
        printf("[");
        printf("%d", matrix[i][0]);
        for(int j = 1; j < matrixColSize; ++j)
        {
            printf(", %d", matrix[i][j]);
        }
        printf("]");
    }
    printf("]\n");
}
