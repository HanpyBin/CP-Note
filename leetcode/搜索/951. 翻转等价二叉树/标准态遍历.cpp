// 也是排序的思想，化为统一形式即可
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void Dfs(TreeNode* root, vector<int>& q)
    {
        if (root)
        {
            q.push_back(root->val);
            int x = root->left == nullptr ? -1 : root->left->val;
            int y = root->right == nullptr ? -1 : root->right->val;
            if (x < y)
            {
                Dfs(root->left, q);
                Dfs(root->right, q);
            }
            else
            {
                Dfs(root->right, q);
                Dfs(root->left, q);
            }
        }
        q.push_back(-2);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        vector<int> q1, q2;
        Dfs(root1, q1);
        Dfs(root2, q2);
        return q1 == q2;
    }
};