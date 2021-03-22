#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeSort(struct ListNode *list_1, struct ListNode *list_2)
{

    if(!list_1)
        return list_2;
    if(!list_2)
        return list_1;

    if(list_1->val <= list_2->val)
    {
        list_1->next = mergeSort(list_1->next, list_2);
        return list_1;
    }
    else
    {
        list_2->next = mergeSort(list_1, list_2->next);
        return list_2;
    }
}

struct ListNode *sortList(struct ListNode *head)
{
    struct ListNode *pre_node, *fast_node, *slow_node;

    if(!head)
    {
        return NULL;
    }
    if(!head->next)
    {
        return head;
    }

    pre_node = NULL;
    fast_node = slow_node = head;
    while(fast_node && fast_node->next)
    {
        pre_node = slow_node;
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;
    }

    pre_node->next = NULL;

    return mergeSort(sortList(head), sortList(slow_node));
}

int main(int argc, char *argv[])
{
    struct ListNode head[4];
    struct ListNode *answer;

    head[0].val = 4;
    head[0].next = &head[1];
    head[1].val = 2;
    head[1].next = &head[2];
    head[2].val = 1;
    head[2].next = &head[3];
    head[3].val = 3;
    head[3].next = NULL;

    answer = sortList(head);

    while(answer)
    {
        printf("%d ", answer->val);
        answer = answer->next;
    }

    return 0;
}
