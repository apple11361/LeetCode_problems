#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **dp;

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int row_size, col_size;

    row_size = obstacleGridSize;
    col_size = obstacleGridColSize[0];

    dp = (int **)malloc(row_size * sizeof(int *));
    for(int i = 0; i < row_size; ++i)
    {
        dp[i] = (int *)malloc(col_size * sizeof(int));
        memset(dp[i], 0, col_size * sizeof(int));
    }

    for(int i = 0; i < row_size; ++i)
    {
        if(obstacleGrid[i][0])
            break;
        dp[i][0] = 1;
    }
    for(int i = 0; i < col_size; ++i)
    {
        if(obstacleGrid[0][i])
            break;
        dp[0][i] = 1;
    }

    for(int i = 1; i < row_size; ++i)
    {
        for(int j = 1; j < col_size; ++j)
        {
            if(obstacleGrid[i][j])
                continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[row_size-1][col_size-1];
}

int main(int argc, char *argv[])
{
    int **grid;
    int m, n, answer;

    m = n = 3;

    grid = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; ++i)
    {
        grid[i] = (int *)malloc(n * sizeof(int));
    }

    grid[0][0] = 0;
    grid[0][1] = 0;
    grid[0][2] = 0;
    grid[1][0] = 0;
    grid[1][1] = 1;
    grid[1][2] = 0;
    grid[2][0] = 0;
    grid[2][1] = 0;
    grid[2][2] = 0;

    answer = uniquePathsWithObstacles(grid, m, &n);

    printf("%d\n", answer);

    return 0;
}
