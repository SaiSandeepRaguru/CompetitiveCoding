class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<int> q;
        int n=image.size();
        int m=image[0].size();
        q.push(sr*m+sc);
        int dir[][4]={{-1,0},{0,1},{0,-1},{1,0}};
        if(image[sr][sc]==color){
            return image;
        }
        int orgcolor = image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int top=q.front();
                q.pop();
                int xc = top/m;
                int yc = top%m;
                for(int i=0;i<4;i++){
                    int nxc = xc + dir[i][0];
                    int nyc = yc + dir[i][1];
                    if(nxc>=0 && nxc<n && nyc>=0 && nyc<m && image[nxc][nyc]==orgcolor){
                        image[nxc][nyc]=color;
                        q.push(nxc*m+nyc);
                    }
                }
            }
        }
        return image;
        
    }
};