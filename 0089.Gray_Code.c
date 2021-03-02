#include <stdio.h>
#include <stdlib.h>

int *grayCode(int n, int *returnSize)
{
    int *answer;
    int ret_size;
    int reflect_index;

    ret_size = 1;
    ret_size = ret_size << n;
    answer = (int *)malloc(ret_size * sizeof(int));
    answer[0] = 0;
    reflect_index = 1;

    while(n--)
    {
        for(int i = 0; i < reflect_index; ++i)
        {
            answer[reflect_index + i] = reflect_index | answer[reflect_index - 1 - i];
        }
        reflect_index = reflect_index << 1;
    }

    *returnSize = ret_size;
    return answer;
}

int main()
{
    int n = 2;
    int returnSize;
    int *answer;

    answer = grayCode(n, &returnSize);

    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", answer[i]);
    }

    return 0;
}
