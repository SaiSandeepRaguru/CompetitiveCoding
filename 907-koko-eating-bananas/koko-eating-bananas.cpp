class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=piles[0];
        for(int x: piles){
            high=max(high,x);
        }
        int ans = high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long count=0;
            for(int x: piles){
                count +=ceil(x/(1.0*mid));
            }
            if(count<=h){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};