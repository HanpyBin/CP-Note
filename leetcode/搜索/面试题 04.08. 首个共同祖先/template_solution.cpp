/**
 * 作者：shushengmoon
 * 链接：https://leetcode-cn.com/problems/first-common-ancestor-lcci/solution/zu-xian-lei-de-mo-ban-ti-mu-hui-yi-ti-de-0m6c/
 * 来源：力扣（LeetCode）
 * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p||root==q){       //可以理解为对于要寻找的节点的判断
            return root;
        }
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL&&right!=NULL){
            return root;            //找到
        }
        if(left==NULL&&right==NULL){
            return NULL;
        }
        return left==NULL? right:left; //找到可能的节点返回该节点
    }
};