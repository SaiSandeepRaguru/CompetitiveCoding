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
        TreeNode* cur=root;
        while(cur!=nullptr){
            int val = cur->val;
            if(val==pval || val==qval || (val>pval && val<qval) || (val<pval && val>qval)){
                return cur;
            }
            if(pval<val) cur=cur->left; 
            else cur = cur->right;
        }
        return nullptr;
    }
};