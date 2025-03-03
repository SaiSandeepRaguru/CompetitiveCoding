class Solution {
public:
    unordered_map<int,vector<int>> mp;
    bool dfs(int node,unordered_set<int> &visited){
        if(visited.find(node)!=visited.end()){
            return false;
        }
        if(mp.find(node)==mp.end() || mp[node].empty()){
            return true;
        }

        visited.insert(node);
        for(int x:mp[node]){
            if(dfs(x,visited)==false){
                return false;
            }
        }
        visited.erase(visited.find(node));
        mp[node]={};
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int> vt: prerequisites){
            if(mp.find(vt[0])==mp.end()){
                mp[vt[0]]={vt[1]};
            }
            else{
                mp[vt[0]].push_back(vt[1]);
            }
        }
        unordered_set<int> visited;
        for(int i=0;i<numCourses;i++){
            bool result = dfs(i,visited);
                if(result==false){
                    return result;
                }
        }
        return true;
    }
};