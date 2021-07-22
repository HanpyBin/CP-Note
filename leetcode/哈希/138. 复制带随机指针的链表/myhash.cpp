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
        // return head;
        unordered_map<Node*, Node*> um;
        Node* new_head = NULL;
        Node *p = head, *q;
        while (p)
        {
            Node* t = new Node(p->val);
            if (!new_head)
                new_head = t;
            else
                q->next = t;
            q = t;
            um[p] = t;
            p = p->next;
        }
        p = head;
        while (p)
        {
            um[p]->random = um[p->random];
            p = p->next;
        }
        return new_head;
    }
};