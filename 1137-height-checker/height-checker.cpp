class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(heights.begin(),heights.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=sorted[i]){
                cnt++;
            }
        }
        return cnt;
    }
};