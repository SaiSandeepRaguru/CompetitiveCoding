class Solution {
public:
    int func(int x)
    {
        int c=0;
        while(x!=0)
        {
            x&=(x-1);
            c++;
        }
        return c;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> p;
        for(int x: arr)
        {
            p.push_back(vector<int> {func(x),x});
        }
        sort(p.begin(),p.end());
        vector<int> r;
        for(vector<int> s: p)
        {
            r.push_back(s[1]);
        }
        return r;
    }
};