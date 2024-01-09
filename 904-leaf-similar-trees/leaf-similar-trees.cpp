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
    vector<int> sequence(TreeNode* r)
    {
        stack<TreeNode*> q;
        vector<int> v;
        q.push(r);
        while(!q.empty())
        {
            TreeNode* t = q.top();
            q.pop();
            if(t->left==nullptr && t->right==nullptr)
            {
                v.push_back(t->val);
            }
            if(t->left!=nullptr)
            q.push(t->left);
            if(t->right!=nullptr)
            q.push(t->right);
        }
        return v;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1=sequence(root1);
        vector<int> v2=sequence(root2);
        if(v1.size()!=v2.size())
         return false;
        for(int i=0;i<v1.size();i++)
        {cout<<v1[i]<<" "<<v2[i]<<endl;
         if(v1[i]!=v2[i])
        return false;}
        return true;
        
    }
};