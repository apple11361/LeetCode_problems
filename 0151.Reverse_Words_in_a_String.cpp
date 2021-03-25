#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> my_stack;
        string answer = "";

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                continue;
            }
            else
            {
                int j = i;
                int count = 0;

                while(s[j] != ' ' && j < s.size())
                {
                    ++j;
                    ++count;
                }

                my_stack.push(s.substr(i, count));

                i = j;
            }
        }

        if(my_stack.empty())
            return answer;

        answer = my_stack.top();
        my_stack.pop();

        while(!my_stack.empty())
        {
            answer = answer + " ";
            answer = answer + my_stack.top();
            my_stack.pop();
        }

        return answer;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s = "the sky is blue";
    string answer;

    answer = sol.reverseWords(s);

    cout<<answer<<endl;

    return 0;
}
