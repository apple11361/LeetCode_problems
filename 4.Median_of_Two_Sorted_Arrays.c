double findKthValue(int* nums1, int nums1Size, int i, int *nums2, int nums2Size, int j, int k) {
    if(i >= nums1Size)  //equal is ok
    {
        return (double)nums2[j+k-1];
    }
    if(j >= nums2Size)  //equal is ok
    {
        return (double)nums1[i+k-1];
    }
    if(k == 1)
    {
        if(nums1[i]<nums2[j])
            return (double)nums1[i];
        else
            return (double)nums2[j];
    }
    
    int midVal1 = i+k/2-1 < nums1Size ? nums1[i+k/2-1] : INT_MAX;
    int midVal2 = j+k/2-1 < nums2Size ? nums2[j+k/2-1] : INT_MAX;
    if(midVal1 > midVal2)
    {
        return findKthValue(nums1, nums1Size, i, nums2, nums2Size, j+k/2, k-k/2);
    }
    else
    {
        return findKthValue(nums1, nums1Size, i+k/2, nums2, nums2Size, j, k-k/2);
    }
    
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int temp1 = (nums1Size + nums2Size + 1) / 2;
    int temp2 = (nums1Size + nums2Size + 2) / 2;
    double ans1 = findKthValue(nums1, nums1Size, 0, nums2, nums2Size, 0, temp1);
    double ans2 = findKthValue(nums1, nums1Size, 0, nums2, nums2Size, 0, temp2);
    double ans = (ans1 + ans2) / 2;
    
    return ans;
}


