#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

int main()
{
    struct ListNode testcase1[5], testcase2[5], *return_value;

    testcase1[0].val = 1;
    testcase1[1].val = 4;
    testcase1[2].val = 6;
    testcase1[3].val = 8;
    testcase1[4].val = 10;

    testcase1[0].next = &testcase1[1];
    testcase1[1].next = &testcase1[2];
    testcase1[2].next = &testcase1[3];
    testcase1[3].next = &testcase1[4];
    testcase1[4].next = NULL;

    testcase2[0].val = 1;
    testcase2[1].val = 5;
    testcase2[2].val = 9;
    testcase2[3].val = 9;
    testcase2[4].val = 10;

    testcase2[0].next = &testcase2[1];
    testcase2[1].next = &testcase2[2];
    testcase2[2].next = &testcase2[3];
    testcase2[3].next = &testcase2[4];
    testcase2[4].next = NULL;

    return_value = mergeTwoLists(&testcase1[0], &testcase2[0]);

    while(return_value)
    {
        printf("%d ", return_value->val);
        return_value = return_value->next;
    }

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *ret_val, *current_node;

    if(l1 || l2)
    {
        ret_val = (struct ListNode *)malloc(sizeof(struct ListNode));
        current_node = ret_val;

        if(l1)
        {
            if(l2)
            {
                if(l1->val > l2->val)
                {
                    current_node->val = l2->val;
                    current_node->next = NULL;

                    l2 = l2->next;
                }
                else
                {
                    current_node->val = l1->val;
                    current_node->next = NULL;

                    l1 = l1->next;
                }
            }
            else
            {
                current_node->val = l1->val;
                current_node->next = NULL;

                l1 = l1->next;
            }
        }
        else
        {
            current_node->val = l2->val;
            current_node->next = NULL;

            l2 = l2->next;
        }
    }
    else
    {
        return NULL;
    }

    while(l1)
    {
        current_node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current_node = current_node->next;
        current_node->next = NULL;
        if(l2)
        {
            if(l1->val > l2->val)
            {
                current_node->val = l2->val;

                l2 = l2->next;
            }
            else
            {
                current_node->val = l1->val;

                l1 = l1->next;
            }
        }
        else
        {
            current_node->val = l1->val;

            l1 = l1->next;
        }
    }

    while(l2)
    {
        current_node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current_node = current_node->next;
        current_node->next = NULL;
        current_node->val = l2->val;

        l2 = l2->next;
    }

    return ret_val;
}
