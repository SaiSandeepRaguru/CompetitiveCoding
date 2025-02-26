class Solution {
public:
    int findMin(vector<int>& a) {
        int low=0,high=a.size()-1;
        int ans=a[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[low]<=a[high]){
                return min(ans,a[low]);
            }
            if(a[low]<=a[mid]){
                ans=min(ans,a[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,a[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};