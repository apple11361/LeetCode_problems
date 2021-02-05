#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    int row_size = matrixSize;
    int col_size = matrixColSize[0];
    int left_index, right_index, mid_index;
    int target_row_index;

    // Find which row
    left_index = 0;
    right_index = row_size-1;
    while(left_index < right_index)
    {
        mid_index = (left_index + right_index) / 2;

        if(target <= matrix[mid_index][col_size-1])
            right_index = mid_index;
        else
            left_index = mid_index + 1;
    }
    target_row_index = left_index;

    // Find the value in target row
    left_index = 0;
    right_index = col_size - 1;
    while(left_index < right_index)
    {
        mid_index = (left_index + right_index) / 2;

        if(target == matrix[target_row_index][mid_index])
            return true;
        else if(target < matrix[target_row_index][mid_index])
            right_index = mid_index - 1;
        else
            left_index = mid_index + 1;
    }

    // Special case, 1*1 matrix
    if(target == matrix[target_row_index][left_index])
        return true;

    return false;
}

int main(int argc, char *argv[])
{
    int **matrix;
    int matrixSize, matrixColSize;
    int target;
    int answer;

    matrixSize = 3;
    matrixColSize = 4;

    matrix = (int **)malloc(matrixSize * sizeof(int *));
    for(int i = 0; i < matrixSize; ++i)
    {
        matrix[i] = (int *)malloc(matrixColSize * sizeof(int));
    }

    matrix[0][0] = 1;
    matrix[0][1] = 3;
    matrix[0][2] = 5;
    matrix[0][3] = 7;
    matrix[1][0] = 10;
    matrix[1][1] = 11;
    matrix[1][2] = 16;
    matrix[1][3] = 20;
    matrix[2][0] = 23;
    matrix[2][1] = 30;
    matrix[2][2] = 34;
    matrix[2][3] = 60;

    answer = searchMatrix(matrix, matrixSize, &matrixColSize, 13);

    if(answer)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
