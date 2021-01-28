#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack()
    {
        if(temp_answer.size() == local_nums.size())
        {
            answer.push_back(temp_answer);

            return;
        }

        for(int i = 0; i < nums_size; ++i)
        {
            if(is_chosen[i])
                continue;
            if(i > 0 && local_nums[i] == local_nums[i-1] && !is_chosen[i-1])
                continue;

            temp_answer.push_back(local_nums[i]);
            is_chosen[i] = true;
            backtrack();
            temp_answer.pop_back();
            is_chosen[i] = false;
        }
    }

    vector<vector<int>> answer;
    vector<int> temp_answer;
    vector<bool> is_chosen;
    vector<int> local_nums;
    int nums_size;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        nums_size = nums.size();
        local_nums.assign(nums.begin(), nums.end());
        is_chosen.assign(nums.size(), false);

        backtrack();

        return answer;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums{1, 2, 1};
    vector<vector<int>> answer;
    Solution sol;

    answer = sol.permuteUnique(nums);

    for(int i = 0; i < answer.size(); ++i)
    {
        copy(answer[i].begin(), answer[i].end(), ostream_iterator<int>(cout, " "));

        cout<<endl;
    }

    return 0;
}
