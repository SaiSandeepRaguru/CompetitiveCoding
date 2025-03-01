/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val,qval = q->val;
        if(root->val==pval || root->val==qval){
            return root;
        }
        if((root->val<pval && root->val>qval) || (root->val<qval && root->val>pval)){
            return root;
        }
        return pval < root->val ? lowestCommonAncestor(root->left,p,q) : lowestCommonAncestor(root->right,p,q);
    }
};