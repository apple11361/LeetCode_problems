#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isValid(char * s);

int main()
{
    char *input = "(){}[]";
    int retval;

    retval = isValid(input);

    if(retval)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}

bool isValid(char * s)
{
    char *stack;
    int stack_size;
    int sp, i;

    stack_size = strlen(s);
    stack_size = stack_size | 1 + stack_size >> 1;
    stack = (char *)malloc(stack_size);
    memset(stack, 0, stack_size);

    i = 0;
    sp = 0;
    while(s[i])
    {
       switch(s[i])
       {
           case '(':
           case '{':
           case '[':
               if(sp == stack_size)
                   return false;
               stack[sp++] = s[i];
               break;
           case ')':
               if(sp == 0)
                   return false;
               if(stack[--sp]!='(')
                   return false;
               break;
           case '}':
               if(sp == 0)
                   return false;
               if(stack[--sp]!='{')
                   return false;
               break;
           case ']':
               if(sp == 0)
                   return false;
               if(stack[--sp]!='[')
                   return false;
               break;
       }
       i++;
    }

    if(sp != 0)
        return false;

    return true;
}
