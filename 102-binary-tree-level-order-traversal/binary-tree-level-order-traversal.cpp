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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> vt;
            while(size){
                TreeNode* top = q.front(); q.pop();
                vt.push_back(top->val);
                if(top->left!=nullptr){
                    q.push(top->left);
                }
                if(top->right!=nullptr){
                    q.push(top->right);
                }
                size--;
            }
            res.push_back(vt);
        }
        return res;  
    }
};