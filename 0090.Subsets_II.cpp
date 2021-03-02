#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
private:
    void backtrack(int answer_len, int temp_answer_len, int index)
    {
        if(temp_answer_len == answer_len)
        {
            answer.push_back(temp_answer);
            return;
        }

        for(int i = index; i <= nums_size + temp_answer_len - answer_len ; ++i)
        {
            if(i != index && local_nums[i] == local_nums[i-1])
                continue;

            temp_answer.push_back(local_nums[i]);
            backtrack(answer_len, temp_answer_len + 1, i + 1);
            temp_answer.pop_back();
        }
    }
    vector<vector<int>> answer;
    vector<int> temp_answer;
    vector<int> local_nums;
    int nums_size;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        nums_size = nums.size();

        sort(nums.begin(), nums.end());
        local_nums.assign(nums.begin(), nums.end());

        for(int i = 0; i <= nums_size; ++i)
        {
            backtrack(i, 0, 0);
        }

        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 2, 2};
    vector<vector<int>> answer;

    answer = sol.subsetsWithDup(nums);

    for(int i = 0; i < answer.size(); ++i)
    {
        copy(answer[i].begin(), answer[i].end(), ostream_iterator<int>(cout, " "));

        cout<<endl;
    }

    return 0;
}
