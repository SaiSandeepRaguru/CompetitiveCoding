class Solution {
public:
void dfs(int i,int n,vector<vector<int>> edges,bool visited[]){
        stack<int> st;
        visited[i]=true;
        st.push(i);
        while(!st.empty()){
            int top = st.top();
            st.pop();
            for(int i=0;i<n;i++){
                if(i!=top && edges[top][i]==1 && !visited[i]){
                    visited[i]=true;
                    st.push(i);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& edges) {
        int n=edges.size();
         int cc=0;
        bool visited[n];
        memset(visited, false, sizeof(visited));
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cout<<i<<endl;
                dfs(i,n,edges,visited);
                cc++;
            }
        }
        return cc;
        
    }
};