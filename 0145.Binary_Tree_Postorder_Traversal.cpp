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
    vector<int> postorderTraversal(TreeNode* root)
    {
        dfs(root);

        return answer;
    }
private:
    void dfs(TreeNode *node)
    {
        if(!node)
            return;
        
        dfs(node->left);
        dfs(node->right);
        answer.push_back(node->val);
    }

    vector<int> answer;
};

int main(int argc, char *argv[])
{
    TreeNode root[3];
    Solution sol;
    vector<int> answer;

    root[0].val = 1;
    root[0].left = NULL;
    root[0].right = &root[1];
    root[1].val = 2;
    root[1].left = &root[2];
    root[1].right = NULL;
    root[2].val = 3;
    root[2].left = NULL;
    root[2].right = NULL;

    answer = sol.postorderTraversal(root);

    for(int i = 0; i < answer.size(); ++i)
    {
        printf("%d ", answer[i]);
    }

    return 0;
}
