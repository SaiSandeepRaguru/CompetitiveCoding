class Solution {
public:
    int divide(int start,int end,vector<int> &nums){
        if(start==end){
            return nums[start];
        }
        int mid=(start+end)/2;
        int lmax=divide(start,mid,nums);
        int rmax=divide(mid+1,end,nums);
        int lmaxi=INT_MIN,rmaxi=INT_MIN,cl=0,rl=0;
        for(int i=mid;i>=start;i--){
            cl+=nums[i];
            lmaxi=max(lmaxi,cl);
        }
        for(int i=mid+1;i<=end;i++){
            rl+=nums[i];
            rmaxi=max(rmaxi,rl);
        }
        return max(lmax,max(rmax,lmaxi+rmaxi));
    }
    int maxSubArray(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        return divide(start,end,nums);
    }
};