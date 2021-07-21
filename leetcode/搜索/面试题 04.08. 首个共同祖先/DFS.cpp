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
    TreeNode* res;
    Solution()
    {
        res = NULL;
    }
    int Dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
            return 0;
        int sum = (root == p || root == q) + Dfs(root->left, p, q) + Dfs(root->right, p, q);
        if (!res && sum == 2)
            res = root;
        return sum;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // LCA
        Dfs(root, p, q);
        return res;
    }
};