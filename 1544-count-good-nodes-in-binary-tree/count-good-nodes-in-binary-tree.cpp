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
    int nodesWithGreaterThanMax(TreeNode* root, int maxi) {
        if(root==nullptr){
            return 0;
        }
        if(root->val>=maxi){
            cout<<root->val<<endl;
            return 1+nodesWithGreaterThanMax(root->left,root->val)+nodesWithGreaterThanMax(root->right,root->val);
        }
        return nodesWithGreaterThanMax(root->left,maxi)+nodesWithGreaterThanMax(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        return nodesWithGreaterThanMax(root,INT_MIN);
    }
};