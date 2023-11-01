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
    unordered_map<int,int> mp;
    void traverse(TreeNode* node)
    {
        if(node==NULL)
         return;
        traverse(node->left);
        if(mp.find(node->val)==mp.end())
        mp[node->val]=1;
        else
        mp[node->val]++;
        traverse(node->right);

    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        //find the mode
        int res=root->val,count=1;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(i->second>count)
            {
                count=i->second; res=i->first;
            }
        }
        //return res
        vector<int> ans;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(i->second==count)
            {
                ans.push_back(i->first);
            }
        }
        return ans;

        
    }
};