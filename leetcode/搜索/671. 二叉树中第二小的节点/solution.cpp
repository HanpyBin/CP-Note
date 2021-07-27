class Solution
{
public:
    int Dfs(TreeNode* root, int x)
    {
        int a = -1, b = -1;
        if (!(root->left))
            return -1;
        if (root->left->val == x && root->right->val == x)
        {
            a = Dfs(root->left, x);
            b = Dfs(root->right, x);
            if (a == -1)
				return b;
            else
            {
				if (b == -1)
                	return a;
				else
					return min(a, b);
            }
        }
        else if (root->left->val == x)
        {
            a = Dfs(root->left, x);
            if (a == -1)
                return root->right->val;
            return min(root->right->val, a);
        }
        else
        {
            // cout << 3 << endl;
            a = Dfs(root->right, x);
            if (a == -1)
                return root->left->val;
            return min(root->left->val, a);
        }
        return -1;
    }
    int findSecondMinimumValue(TreeNode* root)
    {
        if (!root)
            return -1;
        return Dfs(root, root->val);
    }
};