class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,1},{0,-1},{1,0}};
    void findHighestHeight(vector<vector<int>>& heights,queue<pair<int,int>> &q,vector<vector<bool>> &visited){
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front(); q.pop();
                int x=p.first,y=p.second;
                visited[x][y]=true;
                bool flag=false;
                for(int j=0;j<4;j++){
                    int nx =x+dir[j][0];
                    int ny =y+dir[j][1];
                    if(nx>=0 && ny>=0 && nx<heights.size() && ny<heights[0].size() && !visited[nx][ny] && heights[nx][ny]>=heights[x][y]){
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> pacificVisited(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlanticVisited(heights.size(), vector<bool>(heights[0].size(), false));
        queue<pair<int,int>> pacific,atlantic;
        int r=heights.size(),c=heights[0].size();
        for(int i=0;i<r;i++){
            pacific.push({i,0});
            atlantic.push({i,c-1});
        }
        for(int i=0;i<c;i++){
            pacific.push({0,i});
            atlantic.push({r-1,i});
        }
        map<pair<int,int>,int> hmp;
        findHighestHeight(heights,pacific,pacificVisited);
        findHighestHeight(heights,atlantic,atlanticVisited);
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};