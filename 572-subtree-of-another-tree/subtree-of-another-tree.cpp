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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr){
            return true;
        }
        if(p==nullptr || q==nullptr){
            return false;
        }
        if(p->val==q->val){
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr){
            return true;
        }
        if(root==nullptr){
            return false;
        }
        if(root->val==subRoot->val){
            if (isSameTree(root,subRoot)==true){
                return true;
            }
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};