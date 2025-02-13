class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int i=0;
        for(int x: nums){
            if(mp.find(target-x)!=mp.end()){
                return {mp[target-x],i};
            }
            mp[x]=i; i++;
        }
        return {-1,-1};
    }
};