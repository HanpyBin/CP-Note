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
    void Inorder(vector<int>& v, TreeNode* root)
    {
        if (!root)
            return;
        Inorder(v, root->left);
        v.push_back(root->val);
        Inorder(v, root->right);
        return;
    }
    bool isValidBST(TreeNode* root)
    {
        // xx遍历
        vector<int> v;
        Inorder(v, root);
        for (int i = 1; i < v.size(); i++)
            if (v[i] <= v[i-1])
                return false;
        return true;
    }
};