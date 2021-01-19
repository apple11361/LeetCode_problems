#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer(2, -1);
        int left, right, mid;

        // Find the first answer
        left = 0;
        right = nums.size() - 1;

        while(left <= right)
        {
            mid = (left + right) / 2;

            if(nums[mid] == target)
            {
                answer[0] = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if(answer[0] == -1)
            return answer;

        // Find the second answer
        left = 0;
        right = nums.size() - 1;

        while(left <= right)
        {
            mid = (left + right) / 2;

            if(nums[mid] == target)
            {
                answer[1] = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return answer;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums{5,7,7,8,8,10};
    int target = 8;
    vector<int> answer;
    Solution sol;

    answer = sol.searchRange(nums, target);
    copy(answer.begin(), answer.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
