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
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int,int> &inordermp, int prestart,int preend, int instart,int inend) {
        if(prestart<=preend){
            TreeNode* node = new TreeNode(preorder[prestart]);
            int temp = inordermp[node->val];
            int lefttreesize = temp-instart,righttreesize=inend-temp;
            node->left = buildTree(preorder,inordermp,prestart+1,prestart+lefttreesize,instart,temp-1);
            node->right = buildTree(preorder,inordermp,prestart+lefttreesize+1,preend,temp+1,inend);
            return node;
        }
        return nullptr;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inordermp;
        for(int i=0;i<inorder.size();i++){
            inordermp[inorder[i]]=i;
        }
        return buildTree(preorder,inordermp,0,preorder.size()-1,0,inorder.size()-1);
    }
};