class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        //Initialize a graph, where graph[node] holds a list of neighbors for node.
        map<int,vector<int>> graph;

        /*Iterate over each edge (x, y) in adjacentPairs:
            Add y to graph[x].
            Add x to graph[y].*/
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

        /*Iterate over each num in graph:
            If the length of graph[num] is equal to 1, set root = num and break from the loop.*/
        int start;
        for(auto i=graph.begin();i!=graph.end();i++)
        {
            if(i->second.size()==1)
            {
                start=i->first;
                break;
            }
        }

        /*Define a function dfs(node, prev, ans):
                Add node to ans.
                Iterate over each neighbor in graph[node]:
                    If neighbor != prev:
                        Call dfs(neighbor, node, ans).*/
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