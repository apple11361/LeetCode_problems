#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        int n = nums.size();
        int left, right, sum;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; ++i)
        {
            if(i && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1; j < n - 2; ++j)
            {
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                left = j + 1;
                right = n - 1;

                while(left < right)
                {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target)
                    {
                        vector<int> temp{nums[i], nums[j], nums[left], nums[right]};
                        answer.push_back(temp);

                        while(left < right && nums[left] == nums[left+1])
                            ++left;
                        while(left < right && nums[right] == nums[right-1])
                            --right;

                        ++left;
                        --right;
                    }
                    else if(sum < target)
                    {
                        ++left;
                    }
                    else
                    {
                        --right;
                    }
                }
            }
        }

        return answer;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> answer;
    Solution sol;

    answer = sol.fourSum(nums, target);

    for(int i = 0; i < answer.size(); ++i)
    {
        copy(answer[i].begin(), answer[i].end(), ostream_iterator<int>(cout, " "));

        cout<<endl;
    }

    return 0;
}
