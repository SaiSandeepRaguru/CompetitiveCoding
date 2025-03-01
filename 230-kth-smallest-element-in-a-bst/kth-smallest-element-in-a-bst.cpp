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
    void kthSmallest(TreeNode* root, int k,vector<int> &vt) {
        if(root==nullptr){
            return;
        }
        kthSmallest(root->left,k,vt);
        vt.push_back(root->val);
        if(vt.size()==k){
            return;
        }
        kthSmallest(root->right,k,vt);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vt;
        kthSmallest(root,k,vt);
        if(vt.size()>=k){
            return vt[k-1];
        }
        return -1;
    }
};