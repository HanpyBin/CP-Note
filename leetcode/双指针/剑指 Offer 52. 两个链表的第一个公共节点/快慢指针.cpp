/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // double pointer
        int cntA = 0, cntB = 0;
        ListNode* p = headA;
        while (p)
        {
            cntA++;
            p = p->next;
        }
        p = headB;
        while (p)
        {
            cntB++;
            p = p->next;
        }
        if (cntA > cntB)
        {
            int diff = cntA - cntB;
            while (diff--)
                headA = headA->next;
        }
        else
        {
            int diff = cntB - cntA;
            while (diff--)
                headB = headB->next;
        }
        while (headB)
        {
            if (headA == headB)
                return headB;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};