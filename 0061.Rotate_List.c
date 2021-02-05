#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    int node_num;
    struct ListNode *tail;
    struct ListNode *answer;

    node_num = 0;
    answer = tail = head;

    if(!head)
        return answer;

    while(tail->next)
    {
        node_num += 1;
        tail = tail->next;
    }
    node_num += 1;

    k = k % node_num;

    if(k)
    {
        tail->next = head;
        for(int i = 0; i < node_num - k - 1; ++i)
        {
            head = head->next;
        }
        answer = head->next;
        head->next = NULL;
    }

    return answer;
}

int main()
{
    struct ListNode head[5];
    int k = 2;
    struct ListNode *answer;

    head[0].val = 1;
    head[0].next = &head[1];
    head[1].val = 2;
    head[1].next = &head[2];
    head[2].val = 3;
    head[2].next = &head[3];
    head[3].val = 4;
    head[3].next = &head[4];
    head[4].val = 5;
    head[4].next = NULL;

    answer = rotateRight(head, k);

    while(answer)
    {
        printf("%d ", answer->val);
        answer = answer->next;
    }

    return 0;
}
