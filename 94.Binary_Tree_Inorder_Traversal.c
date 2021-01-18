#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode_t;

int* inorderTraversal(struct TreeNode* root, int* returnSize);
void recursiveVisit(int *answer, struct TreeNode *root, int *returnSize);

int main()
{
    TreeNode_t root, node1, node2;
    int returnSize;
    int *answer;

    root.val = 1;
    root.left = NULL;
    root.right = &node1;

    node1.val = 2;
    node1.left = &node2;
    node1.right = NULL;

    node2.val = 3;
    node2.left = NULL;
    node2.right = NULL;

    answer = inorderTraversal(&root, &returnSize);

    for(int i = 0; i < returnSize; ++i)
    {
        printf("%d ", answer[i]);
    }

    return 0;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *answer;

    answer = (int *)malloc(105 * sizeof(int));
    *returnSize = 0;

    recursiveVisit(answer, root, returnSize);

    return answer;
}

void recursiveVisit(int *answer, struct TreeNode *root, int *returnSize)
{
    if(!root)
    {
        return;
    }
    else
    {
        recursiveVisit(answer, root->left, returnSize);
        answer[(*returnSize)++] = root->val;
        recursiveVisit(answer, root->right, returnSize);
    }
}
