#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int threeSumClosest(int* nums, int numsSize, int target);
int cmp(const void *a, const void *b);

int main(void)
{
    int nums[]={-1, 2, 1, -4};
    int numsSize = 4;
    int target = 1;
    int answer;

    answer = threeSumClosest(nums, numsSize, target);
    printf("%d\n", answer);

    return 0;
}


int cmp(const void *a, const void *b)
{
    int int_a = *(int*)a;
    int int_b = *(int*)b;

    return int_a==int_b?0:int_a>int_b?1:-1;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    int sum, dis, temp_sum;
    int i, left, right;

    dis = INT_MAX;

    qsort(nums, numsSize, sizeof(int), cmp);

    for(i=0;i<numsSize-2;i++)
    {
        right = numsSize-1;
        left = i+1;

        while(right > left)
        {
            temp_sum = nums[i]+nums[left]+nums[right];
            if(abs(temp_sum-target) < dis) {
                dis = abs(temp_sum-target);
                sum = temp_sum;
            }

            if(temp_sum-target > 0) {
                right--;
            }
            else if(temp_sum-target < 0) {
                left++;
            }
            else {
                return temp_sum;
            }
        }
    }

    return sum;
}

