#include <stdio.h>

int maxArea(int *height, int heightSize)
{
    int ans = 0, temp;
    int left = 0, right = heightSize-1;

    while(left < right)
    {
        temp = height[left] < height[right] ? height[left] : height[right];
        temp *= right-left;

        if(temp > ans)
            ans = temp;

        if(height[left]<height[right])
            left++;
        else
            right--;
    }


    return ans;
}

int main(int argc, char *argv[])
{
    int height[] = {1, 8, 6, 2, 100, 103, 5, 4, 8, 3, 7};

    printf("%d\n", maxArea(height, 11));

    return 0;
}
