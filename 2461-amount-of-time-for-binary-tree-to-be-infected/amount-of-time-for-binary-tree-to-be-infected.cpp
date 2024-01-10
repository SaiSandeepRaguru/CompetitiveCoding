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
    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>> mp;
        map<int,bool> mpinfect;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            count++;
            mpinfect[t->val]=false;
            if(t->left!=nullptr)
            {
                q.push(t->left);
                if(mp.find(t->val)!=mp.end())
                mp[t->val].push_back(t->left->val);
                else
                mp[t->val]={t->left->val};
                if(mp.find(t->left->val)!=mp.end())
                mp[t->left->val].push_back(t->val);
                else
                mp[t->left->val]={t->val};
            }
            if(t->right!=nullptr)
            {
                q.push(t->right);
                if(mp.find(t->val)!=mp.end())
                mp[t->val].push_back(t->right->val);
                else
                mp[t->val]={t->right->val};
                if(mp.find(t->right->val)!=mp.end())
                mp[t->right->val].push_back(t->val);
                else
                mp[t->right->val]={t->val};
            }
        }
        int time=0;
        queue<int> infect;
        infect.push(start);
        mpinfect[start]=true;
        while(!infect.empty())
        {
            int size=infect.size();
            for(int i=0;i<size;i++)
            {
                int node=infect.front();
                infect.pop();
                for(int x: mp[node])
                {
                    if(!mpinfect[x])
                    {
                        mpinfect[x]=true;
                        infect.push(x);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};