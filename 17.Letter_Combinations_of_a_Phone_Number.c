#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int size;
    char ch[5];
} digit;
digit all_digit[10];
int digit_len;

void dfs(char *digits, int digit_index, int ch_index, char **output,
    int *returnSize, char *temp_str)
{

    if(digit_index == digit_len)
    {
        temp_str[digit_index] = '\0';
        strcpy(output[*returnSize], temp_str);
        *returnSize += 1;

        return;
    }

    if(ch_index >= all_digit[digits[digit_index]-'0'].size)
    {
        return;
    }

    temp_str[digit_index] = all_digit[digits[digit_index]-'0'].ch[ch_index];
    dfs(digits, digit_index+1, 0, output, returnSize, temp_str);
    dfs(digits, digit_index, ch_index+1, output, returnSize, temp_str);
}

char ** letterCombinations(char *digits, int *returnSize)
{
    int digit_index;
    char **output;
    char *temp_str;
    int output_size;

    all_digit[2].size = 3;
    strcpy(all_digit[2].ch, "abc");
    all_digit[3].size = 3;
    strcpy(all_digit[3].ch, "def");
    all_digit[4].size = 3;
    strcpy(all_digit[4].ch, "ghi");
    all_digit[5].size = 3;
    strcpy(all_digit[5].ch, "jkl");
    all_digit[6].size = 3;
    strcpy(all_digit[6].ch, "mno");
    all_digit[7].size = 4;
    strcpy(all_digit[7].ch, "pqrs");
    all_digit[8].size = 3;
    strcpy(all_digit[8].ch, "tuv");
    all_digit[9].size = 4;
    strcpy(all_digit[9].ch, "wxyz");

    digit_len = strlen(digits);
    *returnSize = 0;
    output_size = 1;

    if(digit_len == 0)  //special case
    {
        return NULL;
    }

    for(int i=0;i<digit_len;i++)
        output_size <<= 2;
    output = (char **)malloc(sizeof(char *)*output_size);
    for(int i=0;i<output_size;i++)
    {
        output[i] = (char *)malloc(sizeof(char)*(digit_len)+1);
    }

    temp_str = (char *)malloc(sizeof(char)*(digit_len)+1);

    dfs(digits, 0, 0, output, returnSize, temp_str);

    return output;
}

int main(void)
{
    char input[] = "23";
    char **output;
    int returnSize;

    output = letterCombinations(input, &returnSize);

    printf("%d\n", returnSize);
    for(int i=0;i<returnSize;i++)
    {
        printf("%s ", output[i]);
    }
    printf("\n");

    return 0;
}
