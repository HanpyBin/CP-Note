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
    TreeNode* f(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = f(nums, left, mid-1);
        root->right = f(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int n = nums.size();
        if (!n)
            return NULL;
        TreeNode* head = new TreeNode(nums[n/2]);
        head->left = f(nums, 0, n/2 - 1);
        head->right = f(nums, n/2+1, n-1);
        return head;
    }
};