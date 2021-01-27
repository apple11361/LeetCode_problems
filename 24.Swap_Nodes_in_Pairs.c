#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){

    struct ListNode *traverse = head;

    while(traverse && traverse->next)
    {
        traverse->val ^= traverse->next->val;
        traverse->next->val ^= traverse->val;
        traverse->val ^= traverse->next->val;

        traverse = traverse->next->next;
    }

    return head;
}

int main()
{
    struct ListNode list[4];
    struct ListNode *answer;

    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;

    answer = swapPairs(&list[0]);

    while(answer)
    {
        printf("%d ", answer->val);

        answer = answer->next;
    }

    return 0;
}
