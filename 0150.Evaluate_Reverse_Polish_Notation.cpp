#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> stack;
        string token;
        int operand1, operand2;

        for(int i = 0; i < tokens.size(); ++i)
        {
            token = tokens[i];

            if(token.compare("+") == 0)
            {
                operand2 = stack.back();
                stack.pop_back();
                operand1 = stack.back();
                stack.pop_back();
                stack.push_back(operand1 + operand2);
            }
            else if(token.compare("-") == 0)
            {
                operand2 = stack.back();
                stack.pop_back();
                operand1 = stack.back();
                stack.pop_back();
                stack.push_back(operand1 - operand2);
            }
            else if(token.compare("*") == 0)
            {
                operand2 = stack.back();
                stack.pop_back();
                operand1 = stack.back();
                stack.pop_back();
                stack.push_back(operand1 * operand2);
            }
            else if(token.compare("/") == 0)
            {
                operand2 = stack.back();
                stack.pop_back();
                operand1 = stack.back();
                stack.pop_back();
                stack.push_back(operand1 / operand2);
            }
            else
            {
                stack.push_back(stoi(token));
            }
        }

        return stack.back();
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int answer;

    answer = sol.evalRPN(tokens);

    cout<<answer<<endl;

    return 0;
}
