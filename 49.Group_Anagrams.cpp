#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> hash_table; /* The key is sorted anagram words */

        for(string &str : strs)
        {
            string temp(str);
            sort(temp.begin(), temp.end());
            hash_table[temp].push_back(str);
        }

        for(pair<string, vector<string>> pair : hash_table)
        {
            answer.push_back(pair.second);
        }

        return answer;
    }
};

int main(int argc, char *argv[])
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> answer;
    Solution sol;

    answer = sol.groupAnagrams(strs);

    for(int i = 0; i < answer.size(); ++i)
    {
        copy(answer[i].begin(), answer[i].end(), ostream_iterator<string>(cout, " "));

        cout<<endl;
    }

    return 0;
}
