#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int mid, left, right;

        left = 0;
        right = nums.size() - 1;

        while(left <= right)
        {
            mid = (left + right) / 2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] <= nums[right])
            {
                if(nums[mid] < target && target <= nums[right])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
            else
            {
                if(nums[left] <= target && target < nums[mid])
                {
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> inputs{4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution solution;

    cout<<solution.search(inputs, target)<<endl;

    return 0;
}
