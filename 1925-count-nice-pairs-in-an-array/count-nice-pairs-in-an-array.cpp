class Solution {
public:
     long long mod = 1000000007;
     int rev(int a)
     {
         int n=0;
         while(a!=0)
         {
             n = n*10 + a%10;
             a/=10;
         }
         return n;
     }
     long long nc2(int a)
     {
         return ((a%mod*(a-1)%mod)%mod/2)%mod;
     }
     int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        vector<int> reve;
        for(int x: nums)
        reve.push_back(rev(x));
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int val= nums[i]-reve[i];
            mp[val]++;
        }
        for(int i=0;i<n;i++)
        {
           int val=nums[i]-reve[i];
           mp[val]--; 
           cnt = (cnt%mod + mp[val]%mod)%mod;
        }
        return cnt;
    }
};