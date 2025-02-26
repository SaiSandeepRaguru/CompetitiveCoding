class Solution {
public:
    bool kokoeats(vector<int>& piles, int h,int speed){
        long ans=0;
        for(int x: piles){
            ans +=ceil(x/(1.0*speed));
        }
        cout<<speed<<" "<<ans<<endl;
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=piles[0];
        for(int x: piles){
            high=max(high,x);
        }
        int ans = high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int temp=kokoeats(piles,h,mid);
            if(temp){
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