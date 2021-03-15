#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        dp.resize(n+1);
        dp[0] = 1;

        for(int i = 1; i <= n; ++i)
        {
            dp[i] = 0;
            for(int j = 0; j < i; ++j)
            {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        
        return dp[n];
    }
private:
    vector<int> dp;
};

int main()
{
    Solution sol;
    int n;
    int answer;

    n = 3;
    answer = sol.numTrees(n);

    cout<<answer<<endl;

    return 0;
}
