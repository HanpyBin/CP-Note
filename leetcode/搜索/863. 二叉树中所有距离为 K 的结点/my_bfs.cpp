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
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& f)
    {
        if (!root)
            return;
        if (root->left)
            f[root->left] = root;
        if (root->right)
            f[root->right] = root;
        dfs(root->left, f);
        dfs(root->right, f);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        // bfs
        // 找到target节点
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> f;
        vector<int> vis(501);
        dfs(root, f);
        queue<TreeNode*> q;
        q.push(target);
        while (k--)
        {
            int n = q.size();
            while (n--)
            {
                TreeNode* temp = q.front();
                q.pop();
                if (!temp || vis[temp->val])
                    continue;
                vis[temp->val] = 1;
                q.push(f[temp]);
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if (temp && !vis[temp->val])
                res.push_back(temp->val);
        }
        return res;
    }
};