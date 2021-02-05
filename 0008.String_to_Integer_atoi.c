#include <stdio.h>
#include <limits.h>
#include <string.h>

int myAtoi(char *str)
{
    int answer = 0;
    int i = 0;
    int offset;
    int flag = 0;
    int sign = 0;

    while(str[i]!='\0')
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(answer > INT_MAX/10)
            {
                return INT_MAX;
            }
            if(answer < INT_MIN/10)
            {
                return INT_MIN;
            }

            answer = answer*10;
            offset = str[i]-'0';

            if(sign)
            {
                if(answer < INT_MIN+offset)
                    return INT_MIN;
                answer -= offset;
            }
            else
            {
                if(answer > INT_MAX-offset)
                    return INT_MAX;
                answer += offset;
            }

            if(!flag)
                flag = 1;
            goto con;
        }

        if(str[i] == ' ')
        {
            if(flag)
                return answer;
            else
                goto con;
        }

        if(str[i] == '-')
        {
            if(flag)
                return answer;
            else
                sign = 1;

            flag = 1;
            goto con;
        }

        if(str[i] == '+')
        {
            if(flag)
                return answer;

            flag = 1;
            goto con;
        }

        break;
con:
        i++;
    }

    return answer;
}


int main(void)
{
    char buf[1024];
    int i = 0;
    int answer;

    while(scanf("%c", buf+i))
    {
        if(buf[i]=='\n')
        {
            buf[i]='\0';
            break;
        }
        i++;
    }

    answer = myAtoi(buf);
    printf("%d", answer);
}
