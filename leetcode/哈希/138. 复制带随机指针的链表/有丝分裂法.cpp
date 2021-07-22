/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if (!head)
            return NULL;
        Node* p = head;
        while (p)
        {
            Node* t = new Node(p->val, p->next, NULL);
            p->next = t;
            p = p->next->next;
        }
        // 完成random的复制
        p = head;
        while (p)
        {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        Node* new_head = p->next;
        while (p->next)
        {
            Node* t = p->next;
            p->next = p->next->next;
            p = t;
        }
        return new_head;
    }
};