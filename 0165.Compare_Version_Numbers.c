#include <stdio.h>
#include <string.h>

int compareVersion(char *version1, char *version2)
{
    int i, j, num1, num2;

    i = 0;
    j = 0;

    while(i < strlen(version1) || j < strlen(version2))
    {
        num1 = 0;
        num2 = 0;

        while(i < strlen(version1) && '0' <= version1[i] && version1[i] <= '9')
        {
            num1 = num1 * 10 + version1[i] - '0';
            ++i;
        }

        while(j < strlen(version2) && '0' <= version2[j] && version2[j] <= '9')
        {
            num2 = num2 * 10 + version2[j] - '0';
            ++j;
        }

        if(num1 > num2)
            return 1;
        else if(num1 < num2)
            return -1;

        ++i;
        ++j;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    char *version1 = "7.5.2.4";
    char *version2 = "7.5.3";
    int answer;

    answer = compareVersion(version1, version2);

    printf("answer: %d\n", answer);

    return 0;
}
