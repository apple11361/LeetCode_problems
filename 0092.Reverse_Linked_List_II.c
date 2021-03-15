#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    struct ListNode *answer = head;
    struct ListNode *previous_pointer = NULL;
    struct ListNode *next_pointer = head->next;
    struct ListNode *left_pointer = head;
    struct ListNode *right_pointer = head;
    head = NULL;    // used to record the previous left pointer

    if(left == right)
        return answer;

    while(--right)
    {
        previous_pointer = right_pointer;
        right_pointer = next_pointer;
        next_pointer = right_pointer->next;
        if(left > 1)
        {
            --left;
            head = left_pointer;
            left_pointer = left_pointer->next;
        }
        else
        {
            right_pointer->next = previous_pointer;
        }

    }

    if(head)
        head->next = right_pointer;
    else
        answer = right_pointer;

    left_pointer->next = next_pointer;

    return answer;
}

int main(int argc, char *argv[])
{
    struct ListNode head[5];
    struct ListNode *answer;
    int left = 2;
    int right = 4;

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

    answer = reverseBetween(head, left, right);

    while(answer)
    {
        printf("%d ", answer->val);
        answer = answer->next;
    }

    return 0;
}

