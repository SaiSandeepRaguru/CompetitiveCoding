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
    int maxPathSumGlobal = INT_MIN;
    int maxSumOneSide(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftSum = max(0,maxSumOneSide(root->left));
        int rightSum = max(0,maxSumOneSide(root->right));
        maxPathSumGlobal = max(maxPathSumGlobal,leftSum+rightSum+root->val);
        return root->val +max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = maxSumOneSide(root);
        return maxPathSumGlobal;
    }
};