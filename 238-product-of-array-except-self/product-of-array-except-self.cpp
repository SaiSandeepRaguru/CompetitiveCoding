class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count_of_zeroes=0,res=1;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count_of_zeroes++;
                st.insert(i);
            }
            else{
                res*=nums[i];
            }
        }
        vector<int> v(nums.size(),0);
        if(count_of_zeroes>1){
            return v;
        }
        if(count_of_zeroes==1){
            v[*st.begin()]=res;
            return v;
        }
        for(int i=0;i<nums.size();i++){
            v[i]=res/nums[i];
        }
        return v;
        
    }
};