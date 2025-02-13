class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int maxi=nums[0];
        // for(int i=0;i<nums.size();i++){
        //     int csum=0;
        //     for(int j=i;j<nums.size();j++){
        //         csum+=nums[j];
        //         maxi=max(maxi,csum);
        //     }
            
        // }
        // return maxi;

        int maxi=nums[0], csum=0;
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            maxi=max(maxi,csum);
            csum=max(csum,0);
        }
        return maxi;
    }
};