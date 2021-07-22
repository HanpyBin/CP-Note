class Solution
{
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2, int depth=1)
    {
		if (root1 && !root2 || root2 && !root1)
			return false;
		if (!root1 && !root2)
			return true;
        if (root1->val != root2->val)
            return false;
        bool res;
        if ((!(root1->left) && !(root2->left) || root1->left && root2->left && root1->left->val == root2->left->val) && (!(root1->right) && !(root2->right) || root1->right && root2->right && root1->right->val == root2->right->val))
            res = flipEquiv(root1->left, root2->left, depth+1) && flipEquiv(root1->right, root2->right, depth+1);
        else if ((!(root1->right) && !(root2->left) || root1->right && root2->left && root1->right->val == root2->left->val) && (!(root1->left) && !(root2->right) || root1->left && root2->right && root1->left->val == root2->right->val))
            res = flipEquiv(root1->right, root2->left, depth+1) && flipEquiv(root1->left, root2->right, depth+1);
		else
			res = false;
        return res;
    }
};