class Solution {
public:
    int rob(vector<int>& a,int start,int end) {
        int count = end-start+1;
        if(count==1){
            return a[start];
        }
        int prev2=0,prev1=0,res=0;
        for(int i=start;i<=end;i++){
            res=max(prev2+a[i],prev1);
            prev2=prev1;
            prev1=res;
        }
        return res;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        return max(rob(nums,0,nums.size()-2),rob(nums,1,nums.size()-1));
    }
};