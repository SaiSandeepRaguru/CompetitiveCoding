class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> q;
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push(i*c+j);
                }
            }
        }
        int level=0; 
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front(); q.pop();
                int xr = x/c,yr=x%c;
                for(int j=0;j<4;j++){
                    int nx = xr+dir[j][0];
                    int ny = yr+dir[j][1];
                    if(nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push(nx*c + ny);
                    }
                }
            }
            if(!q.empty())
            level++;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return level;
    }
};