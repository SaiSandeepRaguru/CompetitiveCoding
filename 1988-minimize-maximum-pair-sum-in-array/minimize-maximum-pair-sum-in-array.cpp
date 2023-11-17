class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int maxi=INT_MIN;
        for(;i<j;i++,j--)
        {
            if (maxi<(nums[i]+nums[j]))
             maxi=nums[i]+nums[j];
        }
        return maxi;
    }
};