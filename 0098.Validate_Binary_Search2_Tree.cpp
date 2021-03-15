#include <iostream>
#include <algorithm>
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
    bool isValidBST(TreeNode* root)
    {
        dfs(root);

        for(int i = 0; i < dfs_result.size() - 1; ++i)
        {
            if(dfs_result[i] >= dfs_result[i+1])
                return false;
        }

        return true;
    }
private:
    void dfs(TreeNode *node)
    {
        if(!node)
            return;

        dfs(node->left);
        dfs_result.push_back(node->val);
        dfs(node->right);
    }

    vector<int> dfs_result;
};

int main()
{
    Solution sol;
    TreeNode root[3];
    bool answer;

    root[0].val = 2;
    root[0].left = &root[1];
    root[0].right = &root[2];
    root[1].val = 1;
    root[1].left = NULL;
    root[1].right = NULL;
    root[2].val = 3;
    root[2].left = NULL;
    root[2].right = NULL;

    answer = sol.isValidBST(&root[0]);
    cout<<answer<<endl;

    return 0;
}
