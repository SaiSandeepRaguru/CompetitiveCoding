class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string s1="Push",s2="Pop";
        vector<string> res;
        int len=target.size();
        int j=0;
        for(int i=1;i<=n && j<len;i++)
        {
            if(i==target[j])
            {
                res.push_back(s1);
                j++;
            }
            else
            {
                res.push_back(s1);
                res.push_back(s2);
            }
        }
        return res;
    }
};