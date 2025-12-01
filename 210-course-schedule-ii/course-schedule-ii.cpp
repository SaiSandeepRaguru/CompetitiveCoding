class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in_deg(numCourses,0);
        for(auto it:prerequisites){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            in_deg[b]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }
        int cnt = 0;
        vector<int> order;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            order.push_back(top);
            cnt++;
            for(auto it:adj[top]){
                in_deg[it]--;
                if(in_deg[it]==0){
                    q.push(it);
                }
            }
        }
        reverse(order.begin(),order.end());
        if(cnt==numCourses){
            return order;
        }
        return {};
    }
};