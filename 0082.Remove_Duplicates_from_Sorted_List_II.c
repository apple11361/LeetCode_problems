#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    int previous_val;
    struct ListNode *answer, *pointer1, *pointer2;
    answer = NULL;
    pointer1 = NULL;
    pointer2 = head;

    while(pointer2)
    {
        previous_val = pointer2->val;
        if(pointer2->next && previous_val == pointer2->next->val)
        {
            while(pointer2 && previous_val == pointer2->val)
                pointer2 = pointer2->next;

            continue;
        }

        if(!answer)
        {
            answer = pointer1 = pointer2;
        }
        else
        {
            pointer1 = pointer1->next = pointer2;
        }

        pointer2 = pointer2->next;
    }

    if(pointer1)
        pointer1->next = NULL;

    return answer;
}

int main()
{
    struct ListNode node[7];
    struct ListNode *answer;

    node[0].val = 1;
    node[0].next = &node[1];
    node[1].val = 1;
    node[1].next = &node[2];
    node[2].val = 3;
    node[2].next = &node[3];
    node[3].val = 3;
    node[3].next = &node[4];
    node[4].val = 4;
    node[4].next = &node[5];
    node[5].val = 4;
    node[5].next = &node[6];
    node[6].val = 5;
    node[6].next = NULL;

    answer = deleteDuplicates(&node[0]);

    while(answer)
    {
        printf("%d ", answer->val);
        answer = answer->next;
    }

    return 0;
}
