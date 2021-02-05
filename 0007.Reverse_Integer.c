#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int answer = 0;

    while(x)
    {
        if(answer > INT_MAX/10 || answer < INT_MIN/10)
            return 0;
        answer = answer*10;
        answer += x%10;
        x = x/10;
    }

    return answer;
}

int main()
{
    int x;
    scanf("%d", &x);

    x = reverse(x);

    printf("%d\n", x);

    return 0;
}
