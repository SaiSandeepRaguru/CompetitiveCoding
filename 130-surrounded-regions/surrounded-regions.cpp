class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    void solve(vector<vector<char>>& grid) {
        queue<int> q;
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='O' && (i==0 || j==0 || i==r-1 || j==c-1)){
                    grid[i][j]='A';
                    q.push(i*c+j);
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front(); q.pop();
                int xr = x/c,yr=x%c;
                grid[xr][yr]='A';
                for(int j=0;j<4;j++){
                    int nx = xr+dir[j][0];
                    int ny = yr+dir[j][1];
                    if(nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]=='O'){
                        grid[xr][yr]='A';
                        q.push(nx*c + ny);
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                grid[i][j] = (grid[i][j]=='A' ? 'O' : 'X');
            }
        }
        return;
    }
};