
/************************************************************************
* Note: The returned array must be malloced, assume caller calls free().
*************************************************************************/

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = (int *)malloc(2*sizeof(int));
    int *table;
    int min = INT_MAX;
    int max;
    int i;
    
    *returnSize = 2;
    
    /* malloc for hash table */
    for(i=0;i<numsSize;i++)
    {
        if(nums[i] < min)
            min = nums[i];
    }
    max = target - min;
    table = (int *)malloc((max - min + 1)*sizeof(int));

	/* init hash table */
    for(i=0;i<max-min+1;i++)
    {
        table[i] = -1;
    }
    
	/* calculate the result */
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]<=max)
        {
            if(table[target-nums[i]-min]!=-1)
            {
                result[0] = table[target-nums[i]-min];
                result[1] = i;
                return result;
            }
            table[nums[i] - min] = i;
        }
    }
    
    return (int *)0;
}

