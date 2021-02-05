#include <stdio.h>
#include <stdlib.h>

int **dp;

int uniquePaths_dp(int start_row_index, int start_col_index, int end_row_index, int end_col_index)
{
    if(start_row_index == end_row_index && start_col_index == end_col_index)
        return 1;
    if(start_row_index > end_row_index || start_col_index > end_col_index)
        return 0;
    if(dp[start_row_index][start_col_index] > -1)
        return dp[start_row_index][start_col_index];

    int answer = 0;
    answer += uniquePaths_dp(start_row_index+1, start_col_index, end_row_index, end_col_index);
    answer += uniquePaths_dp(start_row_index, start_col_index+1, end_row_index, end_col_index);
    dp[start_row_index][start_col_index] = answer;

    return answer;
}

int uniquePaths(int m, int n)
{
    int answer;

    // Solution 1
    // answer = (a+b)!/(a!*b!)
    // (a+b)! may overflow!!!

    // Solution 2: dunamic programming
    dp = (int **)malloc(m * sizeof(int *));
    for(int i = 0; i < m; ++i)
    {
        dp[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; ++j)
        {
            dp[i][j] = -1;
        }
    }

    answer = uniquePaths_dp(0, 0, m-1, n-1);

    return answer;
}

int main(int argc, char *argv[])
{
    int m, n;
    int answer;

    m = 3;
    n = 7;

    answer = uniquePaths(3, 7);

    printf("%d\n", answer);

    return 0;
}
