/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<ListNode*> listOfDepth(TreeNode* tree)
    {
        // layer traversal
        vector<ListNode*> res;
        queue<TreeNode*> q;
        q.push(tree);
        while (!q.empty())
        {
            int n = q.size();
            ListNode* head = NULL;
            ListNode* temp = NULL;
            while (n--)
            {
                TreeNode* t = q.front();
                if (!head)
                    temp = head = new ListNode(t->val);
                else
                    temp = temp->next = new ListNode(t->val);
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                
            }
            res.push_back(head);
        }
        return res;
    }
};