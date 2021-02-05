/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int temp;
    struct ListNode *temp_list;
    struct ListNode *result = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp = l1->val + l2->val;
    l1 = l1->next;
    l2 = l2->next;
    if(temp>9)
    {
        result->val = temp-10;
        temp = 1;
    }
    else
    {
        result->val = temp;
        temp = 0;
    }
    result->next = NULL;
    temp_list = result;
    
    
    for(;l1!=NULL;l1=l1->next)
    {
        if(l2!=NULL)
        {
            temp += l1->val + l2->val;
            temp_list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            if(temp>9)
            {
                temp_list->next->val = temp-10;
                temp = 1;
            }
            else
            {
                temp_list->next->val = temp;
                temp = 0;
            }
            temp_list = temp_list->next;
            temp_list->next = NULL;
            l2 = l2->next;
        }
        else
        {
            temp += l1->val;
            temp_list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            if(temp>9)
            {
                temp_list->next->val = temp-10;
                temp = 1;
            }
            else
            {
                temp_list->next->val = temp;
                temp = 0;
            }
            temp_list = temp_list->next;
            temp_list->next = NULL;
        }
    }
    for(;l2!=NULL;l2=l2->next)
    {
        temp += l2->val;
        temp_list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(temp>9)
        {
            temp_list->next->val = temp-10;
            temp = 1;
        }
        else
        {
            temp_list->next->val = temp;
            temp = 0;
        }
        temp_list = temp_list->next;
        temp_list->next = NULL;
    }
    if(temp!=0)
    {
        temp_list->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp_list->next->val = temp;
        temp = 0;
        temp_list = temp_list->next;
        temp_list->next = NULL;
    }
    return result;
}

