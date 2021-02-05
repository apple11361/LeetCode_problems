#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *** partition(char * s, int* returnSize, int** returnColumnSizes);
int ispalindrome(char *s, int start, int end);
void backtrack(char *s, int *returnSize, int *returnColumnSizes, int substr_begin_index, char **temp_ans, int temp_ans_count, char ****answer);

int main(int argc, char *argv[])
{
    char *s = "aabaa";
    char ***answer;
    int returnSize, *returnColumnSizes;

    answer = partition(s, &returnSize, &returnColumnSizes);

//    printf("%d %d", returnSize, max_solution_size);

    for(int i = 0; i < returnSize; ++i)
    {
        for(int j = 0; j < returnColumnSizes[i]; ++j)
        {
            printf("%s ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}

char *** partition(char * s, int* returnSize, int** returnColumnSizes)
{
    char ***answer, **temp_ans;
    int max_solution_size;

    answer = NULL;

    max_solution_size = strlen(s);
    max_solution_size = 1 << (max_solution_size-1);
    *returnColumnSizes = (int *)malloc(max_solution_size * sizeof(int));


    temp_ans = (char **)malloc(16 * sizeof(char *));

    *returnSize = 0;
    backtrack(s, returnSize, *returnColumnSizes, 0, temp_ans, 0, &answer);

    return answer;
}

void backtrack(char *s, int *returnSize, int *returnColumnSizes, int substr_begin_index, char **temp_ans, int temp_ans_count, char ****answer)
{
    int str_len = strlen(s);

    if(substr_begin_index == str_len)
    {
        int ret_size = *returnSize;

        *answer = (char ***)realloc(*answer, (ret_size+1) * sizeof(char **));
        (*answer)[ret_size] = (char **)malloc(temp_ans_count * sizeof(char *));
        returnColumnSizes[ret_size] = temp_ans_count;

        for(int i = 0; i < temp_ans_count; ++i)
        {
            (*answer)[ret_size][i] = temp_ans[i];
        }

        *returnSize += 1;
        return;
    }

    for(int substr_len = 1; substr_len <= str_len - substr_begin_index; ++substr_len)
    {
        if(ispalindrome(s, substr_begin_index, substr_begin_index + substr_len - 1))
        {
            temp_ans[temp_ans_count] = (char *)malloc((substr_len+1) * sizeof(char));
            for(int j = 0; j < substr_len; ++j)
            {
                temp_ans[temp_ans_count][j] = s[substr_begin_index+j];
            }
            temp_ans[temp_ans_count][substr_len] = '\0';

            backtrack(s, returnSize, returnColumnSizes, substr_begin_index+substr_len, temp_ans, temp_ans_count+1, answer);
        }
    }
}

int ispalindrome(char *s, int start, int end)
{
    while(start < end)
    {
        if(s[start] != s[end])
        {
            return 0;
        }

        ++start;
        --end;
    }

    return 1;
}
