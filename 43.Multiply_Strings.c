#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *multiply(char *num1, char *num2)
{
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    int answer_len = num1_len + num2_len;
    char *answer = (char *)malloc((answer_len + 1) * sizeof(char));

    memset(answer, 0, answer_len+1);

    for(int i = num1_len - 1; i >= 0; --i)
    {
        for(int j = num2_len - 1; j >= 0; --j)
        {
            int offset = num1_len - 1 + num2_len - 1 - i - j;
            int value = (num1[i] - '0') * (num2[j] - '0');
            answer[offset] += value;
            answer[offset+1] += answer[offset] / 10;
            answer[offset] = answer[offset] % 10;
        }
    }

    int head_zero = 1;
    for(int i = answer_len - 1; i >= 0; --i)
    {
        if(!head_zero)
        {
            answer[i] += '0';
            continue;
        }

        if(answer[i] != 0)
        {
            answer[i] += '0';
            head_zero = 0;
        }
    }

    answer_len = strlen(answer);

    for(int i = 0; i < answer_len / 2; ++i)
    {
        answer[i] ^= answer[answer_len-1-i];
        answer[answer_len-1-i] ^= answer[i];
        answer[i] ^= answer[answer_len-1-i];
    }

    if(answer_len == 0)
    {
        answer[0] = '0';
        answer[1] = '\0';
    }

    return answer;
}

int main()
{
    char *num1 = "9";
    char *num2 = "9";
    char *answer;

    answer = multiply(num1, num2);

    printf("%s\n", answer);

    return 0;
}
