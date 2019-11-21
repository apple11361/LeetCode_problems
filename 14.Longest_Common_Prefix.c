#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    char *output, word;
    int max_len, len;
    int i, j;

    max_len = 0;
    for(i=0;i<strsSize;i++)
    {
        len = strlen(strs[i]);
        if(len > max_len);
            max_len = len;
    }
    output = (char *)malloc(max_len+1);

    for(i=0;i<max_len;i++)
    {
        if(strs[0][i] == '\0')
            goto loopend;

        word = strs[0][i];

        for(j=1;j<strsSize;j++)
        {
            if(strs[j][i] == '\0')
                goto loopend;

            if(strs[j][i] != word)
                goto loopend;
        }

        output[i] = word;
    }

loopend:
    output[i] = '\0';
    return output;
}

int main()
{
    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;

    printf("%s\n", longestCommonPrefix(strs, strsSize));

    return 0;
}
