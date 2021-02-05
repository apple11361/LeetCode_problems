#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(int index, int target)
    {
        if(target == 0)
        {
            answer.push_back(temp_answer);
            return;
        }

        for(int i = index; i < local_candidates.size(); ++i)
        {
            if(local_candidates[i] > target)
            {
                return;
            }

            temp_answer.push_back(local_candidates[i]);
            backtrack(i+1, target-local_candidates[i]);
            temp_answer.pop_back();

            while(i < local_candidates.size() - 1 && local_candidates[i] == local_candidates[i+1])
                ++i;
        }
    }

    vector<int> local_candidates;
    vector<int> temp_answer;
    vector<vector<int>> answer;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        local_candidates.assign(candidates.begin(), candidates.end());
        backtrack(0, target);
        return answer;
    }
};

int main(int argc, char *argv[])
{
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5, 1, 1, 1};
    int target = 8;
    vector<vector<int>> answer;
    Solution sol;

    answer = sol.combinationSum2(candidates, target);

    for(int i = 0; i < answer.size(); ++i)
    {
        cout<<"Answer: ";
        copy(answer[i].begin(), answer[i].end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
    }
}
