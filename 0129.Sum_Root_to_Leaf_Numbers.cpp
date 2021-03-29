#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void DFS(int value, struct TreeNode *node)
    {
        value = value * 10 + node->val;

        if(!node->left && !node->right)
        {
            answer += value;
            return;
        }

        if(node->left)
            DFS(value, node->left);

        if(node->right)
            DFS(value, node->right);
    }
    int answer;
public:
    int sumNumbers(TreeNode* root)
    {
        answer = 0;
        
        DFS(0, root);

        return answer;
    }
};

int main()
{
    struct TreeNode root[5];
    Solution sol;
    int answer;

    root[0].val = 4;
    root[0].left = &root[1];
    root[0].right = &root[2];
    root[1].val = 9;
    root[1].left = &root[3];
    root[1].right = &root[4];
    root[2].val = 0;
    root[2].left = NULL;
    root[2].right = NULL;
    root[3].val = 5;
    root[3].left = NULL;
    root[3].right = NULL;
    root[4].val = 1;
    root[4].left = NULL;
    root[4].right = NULL;

    answer = sol.sumNumbers(root);

    cout<<"answer is: "<<answer<<endl;

    return 0;
}
