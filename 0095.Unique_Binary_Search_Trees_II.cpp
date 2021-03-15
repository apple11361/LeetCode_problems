#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        dp.resize(n+1);
        dp[0].push_back(NULL);

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                for(TreeNode *l : dp[j]) // possible left tree
                {
                    for(TreeNode *r : dp[i-j-1]) // possible right tree
                    {
                        TreeNode *new_node = new TreeNode(j+1);
                        new_node->left = l;
                        new_node->right = clone_node_add_offset(r, j+1);

                        dp[i].push_back(new_node);
                    }
                }
            }
        }
        
        return dp[n];
    }
private:
    TreeNode *clone_node_add_offset(TreeNode *node, int offset)
    {
        if(!node)
            return NULL;

        TreeNode *new_node = new TreeNode(node->val + offset);
        new_node->left = clone_node_add_offset(node->left, offset);
        new_node->right = clone_node_add_offset(node->right, offset);

        return new_node;
    }

    vector<vector<TreeNode *>> dp;
};

int main()
{
    Solution sol;
    int n;
    vector<TreeNode *> answer;

    n = 3;
    answer = sol.generateTrees(n);

    return 0;
}
