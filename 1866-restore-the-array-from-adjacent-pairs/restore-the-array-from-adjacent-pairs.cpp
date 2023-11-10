class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        map<int,vector<int>> graph;
        for(vector<int> vt: ap)
        {
            int x=vt[0];
            int y=vt[1];
            if(graph.find(x)==graph.end())
            graph[x]={y}; 
            else
            graph[x].push_back(y);
            if(graph.find(y)==graph.end())
            graph[y]={x}; 
            else
            graph[y].push_back(x);
        }
        int start;
        for(auto i=graph.begin();i!=graph.end();i++)
        {
            if(i->second.size()==1)
            {
                start=i->first;
                break;
            }
        }
        vector<int> res;
        res.push_back(start);
        int prev=-999999999;
        for(int i=1;i<=ap.size();i++)
        {
            for(int x: graph[start])
            {
                if(prev!=x)
                {
                    res.push_back(x);
                    prev=start;
                    start=x;
                    break;
                }
            }
        }
        return res;
    }
};