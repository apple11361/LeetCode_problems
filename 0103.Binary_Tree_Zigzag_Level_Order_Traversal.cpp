#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> bfs_queue;
        vector<vector<int>> answer;
        TreeNode *temp_node;
        int level;
        int queue_len;

        if(!root)
            return answer;

        bfs_queue.push(root);
        level = 0;

        while(!bfs_queue.empty())
        {
            deque<int> temp_deque;

            queue_len = bfs_queue.size();

            while(queue_len--)
            {
                temp_node = bfs_queue.front();
                bfs_queue.pop();

                if(level % 2)
                    temp_deque.push_front(temp_node->val);
                else
                    temp_deque.push_back(temp_node->val);

                if(temp_node->left)
                    bfs_queue.push(temp_node->left);
                if(temp_node->right)
                    bfs_queue.push(temp_node->right);
            }

            answer.push_back({temp_deque.begin(), temp_deque.end()});
            level++;
        }

        return answer;
    }
};

int main()
{
    TreeNode root[1];
    Solution sol;
    vector<vector<int>> answer;

    root[0].val = 1;
    root[0].left = NULL;
    root[0].right = NULL;

    answer = sol.zigzagLevelOrder(&root[0]);

    for(int i = 0; i < answer.size(); ++i)
    {
        copy(answer[i].begin(), answer[i].end(), ostream_iterator<int>(cout, " "));

        cout<<endl;
    }
}
