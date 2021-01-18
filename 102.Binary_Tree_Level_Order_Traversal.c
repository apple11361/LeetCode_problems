#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode_t;

typedef struct CircularQueue {
    TreeNode_t *buffer[512];
    int head_index;
    int tail_index;
} CircularQueue_t;

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

int main()
{
    TreeNode_t root, node1, node2;
    int returnSize, *returnColumnSizes;
    int **answer;

    root.val = 1;
    root.left = NULL;
    root.right = &node1;

    node1.val = 2;
    node1.left = &node2;
    node1.right = NULL;

    node2.val = 3;
    node2.left = NULL;
    node2.right = NULL;

    answer = levelOrder(&root, &returnSize, &returnColumnSizes);

    for(int i = 0; i < returnSize; ++i)
    {
        for(int j = 0; j < returnColumnSizes[i]; ++j)
        {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    CircularQueue_t queue;
    int **answer;
    int *return_col_sizes;
    int next_level_max, current_level_count, current_level_max;
    int answer_index;
    int i;

    // Special case: root == NULL
    if(!root)
    {
        *returnSize = 0;
        return NULL;
    }

    answer = NULL;
    answer_index = 0;
    return_col_sizes = (int *)malloc(1024 * sizeof(int));

    queue.head_index = 0;
    queue.tail_index = 0;

    queue.buffer[queue.head_index++] = root;
    next_level_max = 0;
    current_level_count = 0;
    current_level_max = 1;

    while(queue.tail_index != queue.head_index)
    {
        if(current_level_count == 0)
        {
            answer = (int **)realloc(answer, (answer_index + 1) * sizeof(int *));
            answer[answer_index] = (int *)malloc(current_level_max * sizeof(int));
            return_col_sizes[answer_index] = current_level_max;
            i = 0;
        }

        answer[answer_index][i++] = queue.buffer[queue.tail_index]->val;
        if(queue.buffer[queue.tail_index]->left)
        {
            ++next_level_max;
            queue.buffer[queue.head_index] = queue.buffer[queue.tail_index]->left;
            queue.head_index = (queue.head_index+1 == 512 ? 0 : queue.head_index+1);
        }
        if(queue.buffer[queue.tail_index]->right)
        {
            ++next_level_max;
            queue.buffer[queue.head_index] = queue.buffer[queue.tail_index]->right;
            queue.head_index = (queue.head_index+1 == 512 ? 0 : queue.head_index+1);
        }
        queue.tail_index = (queue.tail_index+1 == 512 ? 0 : queue.tail_index+1);
        ++current_level_count;

        if(current_level_count == current_level_max)
        {
            ++answer_index;
            current_level_count = 0;
            current_level_max = next_level_max;
            next_level_max = 0;
        }
    }

    *returnSize = answer_index;
    *returnColumnSizes = return_col_sizes;
    return answer;
}
