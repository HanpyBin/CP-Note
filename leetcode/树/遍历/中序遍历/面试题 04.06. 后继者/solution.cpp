class Solution
{
public:
    TreeNode* Inorder(TreeNode* root)
    {
        return root->left ? Inorder(root->left) : root;
    }
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode*& s)
    {
        if (p->val == root->val)
            return root->right ? Inorder(root->right): s;
        else if (p->val > root->val)
            return solve(root->right, p, s);
        else
            return solve(root->left, p, s=root);
        return NULL;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        TreeNode* s = NULL;
        return solve(root, p, s);
    }
};