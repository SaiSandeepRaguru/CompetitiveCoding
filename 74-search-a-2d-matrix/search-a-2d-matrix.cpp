class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int m=a[0].size(),n=a.size();
        int low=0,high=m*n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int xc=mid/m,yc=mid%m;
            if(target==a[xc][yc]){
                return true;
            }
            else if(target > a[xc][yc]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};