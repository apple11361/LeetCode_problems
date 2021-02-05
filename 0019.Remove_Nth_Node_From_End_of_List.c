#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

int main()
{
    struct ListNode xTestcase[5], *pxReturnVal;

    xTestcase[0].val = 1;
    xTestcase[0].next = &xTestcase[1];
    xTestcase[1].val = 2;
    xTestcase[1].next = &xTestcase[2];
    xTestcase[2].val = 3;
    xTestcase[2].next = &xTestcase[3];
    xTestcase[3].val = 4;
    xTestcase[3].next = &xTestcase[4];
    xTestcase[4].val = 5;
    xTestcase[4].next = NULL;

    pxReturnVal = removeNthFromEnd(&xTestcase[0], 2);

    while(pxReturnVal)
    {
        printf("%d ", pxReturnVal->val);
        pxReturnVal = pxReturnVal->next;
    }

    return 0;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *pxFirst, *pxSecond, *pxBeforeHead;
    int i;

    pxBeforeHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    pxBeforeHead->next = head;
    pxFirst = pxBeforeHead;
    pxSecond = pxBeforeHead;

    for(i=0;i<n+1;i++)
    {
        pxFirst = pxFirst->next;
    }

    while(pxFirst != NULL)
    {
        pxFirst = pxFirst->next;
        pxSecond = pxSecond->next;
    }

    pxSecond->next = pxSecond->next->next;

    return pxBeforeHead->next;
}
