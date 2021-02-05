#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    int y=0;

    if(x<0 || (x%10==0 && x!=0))
        return 0;

    while(x>y)
    {
        y *= 10;
        y += x%10;
        x /= 10;
    }
    
    if (x==y || x==y/10)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    int x;

    scanf("%d", &x);

    printf("%d", isPalindrome(x));

    return 0;
}
