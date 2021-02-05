#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int matrixSize, int *matrixColSize);

int
main(int argc, char *argv[])
{
    int **matrix = (int **)malloc(4*sizeof(int *));
    *(matrix+0) = (int *)malloc(4*sizeof(int));
    *(matrix+1) = (int *)malloc(4*sizeof(int));
    *(matrix+2) = (int *)malloc(4*sizeof(int));
    *(matrix+3) = (int *)malloc(4*sizeof(int));

    matrix[0][0] = 5;
    matrix[0][1] = 1;
    matrix[0][2] = 9;
    matrix[0][3] = 11;
    matrix[1][0] = 2;
    matrix[1][1] = 4;
    matrix[1][2] = 8;
    matrix[1][3] = 10;
    matrix[2][0] = 13;
    matrix[2][1] = 3;
    matrix[2][2] = 6;
    matrix[2][3] = 7;
    matrix[3][0] = 15;
    matrix[3][1] = 14;
    matrix[3][2] = 12;
    matrix[3][3] = 16;


    rotate((int **)matrix, 4, NULL);

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void
rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int n = matrixSize;

    for(int i = 0; i < n / 2; ++i)
    {
        for(int j = i; j < n - 1 - i; ++j)
        {
            matrix[i][j]         = matrix[i][j] ^ matrix[j][n-1-i] ^ matrix[n-1-i][n-1-j] ^ matrix[n-1-j][i];
            matrix[j][n-1-i]     = matrix[i][j] ^ matrix[j][n-1-i] ^ matrix[n-1-i][n-1-j] ^ matrix[n-1-j][i];
            matrix[n-1-i][n-1-j] = matrix[i][j] ^ matrix[j][n-1-i] ^ matrix[n-1-i][n-1-j] ^ matrix[n-1-j][i];
            matrix[n-1-j][i]     = matrix[i][j] ^ matrix[j][n-1-i] ^ matrix[n-1-i][n-1-j] ^ matrix[n-1-j][i];
            matrix[i][j]         = matrix[i][j] ^ matrix[j][n-1-i] ^ matrix[n-1-i][n-1-j] ^ matrix[n-1-j][i];
        }
    }

}
