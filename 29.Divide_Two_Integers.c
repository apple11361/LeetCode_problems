#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

int divide(int dividend, int divisor);

int
main(int argc, char *argv[])
{
    int dividend, divisor, answer;

    dividend = -2147483648;
    divisor = 2;

    answer = divide(dividend, divisor);

    printf("The answer is: %d\n", answer);
}


int
divide(int dividend, int divisor)
{
    long long int long_dividend, long_divisor;

    long_dividend = (long long int)dividend;
    long_divisor = (long long int)divisor;

    // Boundary case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    int sign;
    long long int answer, temp;

    // sign = 0: pos
    // sign = 1: neg
    sign = (dividend < 0) ^ (divisor < 0);
    answer = temp = 0;

    long_dividend = llabs(long_dividend);
    long_divisor = llabs(long_divisor);

    for(int i = 31; i >= 0; --i)
    {
        if(long_dividend >= temp + (long_divisor << i))
        {
            temp += long_divisor << i;
            answer |= 1LL << i;
        }
    }

    return sign ? -answer : answer;
}
