#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        local_s = s;

        if(local_s.size() > 12)
            return answer;

        backtrack(0);

        return answer;
    }
private:
    void backtrack(int index)
    {
        if(index > local_s.size() || temp_answer.size() > 4)
            return;
        if(index == local_s.size() && temp_answer.size() == 4)
        {
            answer.push_back(temp_answer[0] + "." + temp_answer[1] + "." + temp_answer[2] + "." + temp_answer[3]);
            return;
        }

        for(int i = 1; i <= 3; ++i)
        {
            string sub_string = local_s.substr(index, i);
            if(sub_string.size() == 0 || (sub_string.size() > 1 && sub_string[0] == '0') || stoi(sub_string) > 255)
                continue;
            temp_answer.push_back(sub_string);
            backtrack(index + i);
            temp_answer.pop_back();
        }
    }

    vector<string> answer;
    string local_s;
    vector<string> temp_answer;
};

int main()
{
    Solution sol;
    string s = "25525511135";
    vector<string> answer;

    answer = sol.restoreIpAddresses(s);

    for(int i = 0; i < answer.size(); ++i)
    {
        cout<<answer[i]<<endl;
    }

    return 0;
}
