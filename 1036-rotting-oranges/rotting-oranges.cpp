class Solution {
    
public:

    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        queue<int> q;
        int n=grid.size(),m=grid[0].size();
        int visited[n][m];
        memset(visited,-1,sizeof(visited));
        int time=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push(i*m+j);
                    visited[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            int flag=0;
            for(int i=0;i<sz;i++){
                int top=q.front(); q.pop();
                int xc=top/m;
                int yc=top%m;
                for(int j=0;j<4;j++){
                    int nxc = xc + dir[j][0];
                    int nyc = yc + dir[j][1];
                    if(nxc>=0 && nxc<n && nyc>=0 && nyc<m && visited[nxc][nyc]==-1 && grid[nxc][nyc]==1){
                        flag=1;
                        visited[nxc][nyc]=0;
                        q.push(nxc*m+nyc);
                    }
                }
            }
            if(flag==1)
            time++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==-1 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
        
    }
};