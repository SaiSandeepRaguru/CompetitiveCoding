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
        while(root!=nullptr){
            int val = root->val;
            if(val==p->val || val==q->val || (val>p->val && val<q->val) || (val<p->val && val>q->val)){
                return root;
            }
            if(p->val<val) root=root->left; 
            else root = root->right;
        }
        return nullptr;
    }
};