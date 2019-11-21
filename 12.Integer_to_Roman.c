#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *intToRoman(int num)
{
    char *output;

    output = (char *)malloc(1024);
    strcpy(output, "");

    while(num >= 1000)
    {
       strcat(output, "M"); 
       num -= 1000;
    }

    if(num >= 900)
    {
        strcat(output, "CM");
        num -= 900;
    }
    if(num >= 500)
    {
        strcat(output, "D");
        num -= 500;
    }
    if(num >= 400)
    {
        strcat(output, "CD");
        num -= 400;
    }

    while(num >= 100)
    {
        strcat(output, "C");
        num -= 100;
    }

    if(num >= 90)
    {
        strcat(output, "XC");
        num -= 90;
    }
    if(num >= 50)
    {
        strcat(output, "L");
        num -= 50;
    }
    if(num >= 40)
    {
        strcat(output, "XL");
        num -= 40;
    }

    while(num >= 10)
    {
        strcat(output, "X");
        num -= 10;
    }

    if(num >= 9)
    {
        strcat(output, "IX");
        num -= 9;
    }
    if(num >= 5)
    {
        strcat(output, "V");
        num -= 5;
    }
    if(num >= 4)
    {
        strcat(output, "IV");
        num -= 4;
    }

    while(num >= 1)
    {
        strcat(output, "I");
        num -= 1;
    }

    return output;
}

int main()
{
    int input;

    scanf("%d", &input);

    printf("%s\n", intToRoman(input));

    return 0;
}
