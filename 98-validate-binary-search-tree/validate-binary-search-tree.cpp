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
    bool isValidBST(TreeNode* root,long mini,long maxi){
        if(root==nullptr){
            return true;
        }
        if(root->val<maxi && root->val>mini)
            return isValidBST(root->left,mini,root->val) && isValidBST(root->right,root->val,maxi);
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        if(root->left==nullptr && root->right==nullptr){
            return true;
        }
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
};