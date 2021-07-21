/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int f(TreeNode* root)
    {
        if (!root)
            return 0;
        int l = f(root->left);
        int r = f(root->right);
        return l == -1 || r == -1 || abs(r-l) > 1 ? -1 : 1+max(l, r);
    }
    bool isBalanced(TreeNode* root)
    {
        if (f(root) != -1)
            return true;
        else
            return false;
    }
};