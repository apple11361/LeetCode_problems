#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* You cannot use malloc in simplifyPath() !!!! */

char *simplifyPath(char *path)
{
    char *answer = path;
    char *index = answer;

    while(*path)
    {
        switch(*path)
        {
            case '/':
                *index = '/';
                ++path;
                while(*path == '/')
                    ++path;
                if(*path == '.' && *(path+1) == '.' && *(path+2) == '/')
                {
                    while(index > answer && *--index != '/');
                    path += 2;
                    break;
                }
                if(*path == '.' && *(path+1) == '.' && *(path+2) == '\0')
                {
                    while(index > answer && *(index-1) != '/')
                        --index;
                    path += 2;
                }
                if(*path == '.' && *(path+1) == '/')
                {
                    path += 1;
                    break;
                }
                if(*path == '.' && *(path+1) == '\0')
                {
                    path += 1;
                    break;
                }
                if(*path == '\0')
                {
                    break;
                }
                ++index;
                break;
            default:
                *index = *path;
                ++index;
                ++path;
        }
    }

    *index = '\0';

    return answer;
}

int main(int argc, char *argv[])
{
    char *path = (char *)malloc(256);
    strcpy(path, "/a/../../b/../c//.//");
    char *answer;

    answer = simplifyPath(path);

    printf("%s\n", answer);

    return 0;
}
