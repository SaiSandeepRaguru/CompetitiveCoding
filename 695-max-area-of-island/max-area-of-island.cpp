class Solution {
public:
int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==0){
            return 0;
        }
        visited[i][j]=true;
        int a=dfs(grid,visited,i-1,j);
        int b=dfs(grid,visited,i,j-1);
        int c=dfs(grid,visited,i,j+1);
        int d=dfs(grid,visited,i+1,j);
        return (a+b+c+d+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n, false));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    res=max(res,dfs(grid,visited,i,j));
                }
            }
        }
        return res;
    }
};