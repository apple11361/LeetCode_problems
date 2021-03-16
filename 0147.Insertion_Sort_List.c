#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
    struct ListNode *answer, *temp, *prev_head;

    answer = head;
    prev_head = head;
    head = head->next;

    while(head)
    {
        if(head->val < answer->val)
        {
            prev_head->next = head->next;
            head->next = answer;
            answer = head;
            head = prev_head->next;
            continue;
        }

        temp = answer;

        while(temp != head)
        {
            if(temp->next->val >= head->val)
            {
                if(head != temp->next)
                {
                    prev_head->next = head->next;
                    head->next = temp->next;
                    temp->next = head;
                    head = prev_head->next;
                }
                else
                {
                    prev_head = head;
                    head = head->next;
                }
                break;
            }
            temp = temp->next;
        }
    }
    return answer;
}

int main()
{
    struct ListNode head[5];
    struct ListNode *answer;

    head[0].val = -1;
    head[0].next = &head[1];
    head[1].val = 5;
    head[1].next = &head[2];
    head[2].val = 3;
    head[2].next = &head[3];
    head[3].val = 4;
    head[3].next = &head[4];
    head[4].val = 0;
    head[4].next = NULL;

    answer = insertionSortList(head);

    while(answer)
    {
        printf("%d ", answer->val);

        answer = answer->next;
    }

    return 0;
}
