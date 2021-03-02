#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *answer, *pointer1, *pointer2, *pointer2_head;

    answer = NULL;
    pointer2_head = NULL;
    pointer1 = NULL;    //smaller than x
    pointer2 = NULL;    //greater than or equal to x

    while(head)
    {
        if(head->val >= x)
        {
            if(!pointer2)
            {
                pointer2_head = pointer2 = head;
            }
            else
            {
                pointer2 = pointer2->next = head;
            }
        }
        else
        {
            if(!pointer1)
            {
                answer = pointer1 = head;
            }
            else
            {
                pointer1 = pointer1->next = head;
            }
        }
        head = head->next;
    }
    if(pointer1)
        pointer1->next = pointer2_head;
    if(pointer2)
        pointer2->next = NULL;
    if(!answer)
        answer = pointer2_head;

    return answer;
}

int main()
{
    struct ListNode node[6];
    struct ListNode *answer;
    int x = 3;

    node[0].val = 1;
    node[0].next = &node[1];
    node[1].val = 4;
    node[1].next = &node[2];
    node[2].val = 3;
    node[2].next = &node[3];
    node[3].val = 2;
    node[3].next = &node[4];
    node[4].val = 5;
    node[4].next = &node[5];
    node[5].val = 2;
    node[5].next = NULL;

    answer = partition(&node[0], x);

    while(answer)
    {
        printf("%d ", answer->val);
        answer = answer->next;
    }

    return 0;
}
