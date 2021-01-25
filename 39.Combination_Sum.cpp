#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(int target, int index)
    {
        if(target == 0)
        {
            answer.push_back(temp_answer);

            return;
        }

        for(int i = index; i < local_candidates.size(); ++i)
        {
            if(local_candidates[i] > target)
                return;

            temp_answer.push_back(local_candidates[i]);
            backtrack(target-local_candidates[i], i);
            temp_answer.pop_back();
        }
    }

    vector<int> local_candidates;
    vector<int> temp_answer;
    vector<vector<int>> answer;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return answer;
        sort(candidates.begin(), candidates.end());
        local_candidates.assign(candidates.begin(), candidates.end());
        backtrack(target, 0);
        return answer;
    }
};

int main(int argc, char *argv[])
{
    vector<int> candidates{2, 3, 5};
    int target = 8;
    Solution sol;
    vector<vector<int>> answer;

    answer = sol.combinationSum(candidates, target);

    for(int i = 0; i < answer.size(); ++i)
    {
        copy(answer[i].begin(), answer[i].end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
    }
}
