#include <stdio.h>

int romanToInt(char * s){
    int ans = 0;
    //state 0: I
    //state 1: V
    //state 2: X
    //state 3: L
    //state 4: C
    //state 5: D
    //state 6: M
    //state 7: init state
    unsigned char state = 7;

    while(*s != '\0')
    {
        switch(*s)
        {
            case 'I':
                ans += 1;
                state = 0;
                break;
            case 'V':
                if(state == 0)
                {
                    ans -= 2;
                    ans += 5;
                }
                else
                {
                    ans += 5;
                }
                state = 1;
                break;
            case 'X':
                if(state == 0)
                {
                    ans -= 2;
                    ans += 10;
                }
                else
                {
                    ans += 10;
                }
                state = 2;
                break;
            case 'L':
                if(state == 2)
                {
                    ans -= 20;
                    ans += 50;
                }
                else
                {
                    ans += 50;
                }
                state = 3;
                break;
            case 'C':
                if(state == 2)
                {
                    ans -= 20;
                    ans += 100;
                }
                else
                {
                    ans += 100;
                }
                state = 4;
                break;
            case 'D':
                if(state == 4)
                {
                    ans -= 200;
                    ans += 500;
                }
                else
                {
                    ans += 500;
                }
                state = 5;
                break;
            case 'M':
                if(state == 4)
                {
                    ans -= 200;
                    ans += 1000;
                }
                else
                {
                    ans += 1000;
                }
                state = 6;
        }
        s++;
    }

    return ans;
}

int main(int argc, char *argv[])
{
    char *input = "IX";
    
    printf("%d\n", romanToInt(input));
}
