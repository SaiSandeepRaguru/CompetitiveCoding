class Solution {
public:
int maxProduct(vector<int>& nums) {
    int res=nums[0];
    for(int i=0;i<nums.size();i++){
        int cmax=1;
        for(int j=i;j<nums.size();j++){
            cmax*=nums[j];
            res=max(cmax,res);
        }
    }
        return res;
    }
};