#include <stdio.h>
#include <stdlib.h>

int **dp;

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int row_size, col_size;

    row_size = gridSize;
    col_size = gridColSize[0];

    dp = (int **)malloc(row_size * sizeof(int *));
    for(int i = 0; i < row_size; ++i)
    {
        dp[i] = (int *)malloc(col_size * sizeof(int));
    }

    dp[0][0] = grid[0][0];
    for(int i = 1; i < row_size; ++i)
    {
        dp[i][0] = grid[i][0] + dp[i-1][0];
    }
    for(int i = 1; i < col_size; ++i)
    {
        dp[0][i] = grid[0][i] + dp[0][i-1];
    }

    for(int i = 1; i < row_size; ++i)
    {
        for(int j = 1; j < col_size; ++j)
        {
            dp[i][j] = grid[i][j] + (dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
        }
    }

    return dp[row_size-1][col_size-1];
}

int main(int argc, char *argv[])
{
    int **grid;
    int m, n;
    int answer;

    m = n = 3;
    grid = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; ++i)
    {
        grid[i] = (int *)malloc(n * sizeof(int));
    }

    grid[0][0] = 1;
    grid[0][1] = 3;
    grid[0][2] = 1;
    grid[1][0] = 1;
    grid[1][1] = 5;
    grid[1][2] = 1;
    grid[2][0] = 4;
    grid[2][1] = 2;
    grid[2][2] = 1;

    answer = minPathSum(grid, m, &n);

    printf("%d\n", answer);

    return 0;
}
