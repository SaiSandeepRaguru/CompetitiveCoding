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
    int diameter=0;
    int maxDepth(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            diameter = max(1,diameter);
            return 1;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        diameter=max(diameter,leftDepth+rightDepth+1);
        return 1+max(leftDepth,rightDepth); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int depth=maxDepth(root);
        return diameter-1;
    }
};