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
    int tcount=0;
    pair<int,int> traverse(TreeNode* root)
    {
        if(root==NULL)
         return make_pair(0,0); //to return pair simple way
        pair<int,int> lp,rp;
        lp= traverse(root->left);
        rp= traverse(root->right);
        int sum=lp.first + rp.first + root->val;
        int count=lp.second+rp.second+1;
        if(root->val==(sum/(count)))
          tcount++;
        return make_pair(sum,count);
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> p=traverse(root);
        return tcount;
    }
};