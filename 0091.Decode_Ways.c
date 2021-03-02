#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDecodings(char *s)
{
    int *dp;
    int string_length;

    if(!s || s[0] == '0')
        return 0;

    string_length = strlen(s);
    dp = (int *)malloc((string_length + 1) * sizeof(int));
    memset(dp, 0, string_length * sizeof(int));
    dp[0] = 1;

    for(int i = 1; i <= string_length; ++i)
    {
        dp[i] = s[i-1] == '0' ? 0 : dp[i-1];
        if(i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))
            dp[i] += dp[i-2];
    }

    return dp[string_length];
}

int main()
{
    char *s = "226";
    int answer;

    answer = numDecodings(s);

    printf("%d\n", answer);

    return 0;
}
