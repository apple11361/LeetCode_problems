#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int answer_num;
int **answer;
int *one_answer;

void backtrack(int index, int length, int n, int k)
{
    if(length == k)
    {
        memcpy(answer[answer_num++], one_answer, k * sizeof(int));
        return;
    }

    for(int i = index; n - i >= k - length; ++i)
    {
        one_answer[length] = i+1;
        backtrack(i+1, length+1, n, k);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    unsigned long long int ret_size = 1;
    int *ret_col_size;

    /********************* allocate space for return value ************************/
    // returnSize = n!/(k!(n-k)!)
    for(int i = n; i > k; --i)
    {
        ret_size *= i;
    }
    for(int i = 1; i <= n - k; ++i)
    {
        ret_size /= i;
    }

    ret_col_size = (int *)malloc(ret_size * sizeof(int));
    answer = (int **)malloc(ret_size * sizeof(int *));
    one_answer = (int *)malloc(k * sizeof(int));
    for(int i = 0; i < ret_size; ++i)
    {
        answer[i] = (int *)malloc(k * sizeof(int));
        ret_col_size[i] = k;
    }

    /********************* calculate the result ************************/
    answer_num = 0;
    backtrack(0, 0, n, k);

    *returnColumnSizes = ret_col_size;
    *returnSize = ret_size;
    return answer;
}

int main()
{
    int n = 4;
    int k = 2;
    int returnSize;
    int *returnColumnSizes;
    int **answer;

    answer = combine(n, k, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; ++i)
    {
        for(int j = 0; j < returnColumnSizes[i]; ++j)
        {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}
