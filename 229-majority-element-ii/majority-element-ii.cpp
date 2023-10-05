class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        if(n<=1)
         return nums;
        if(n==2)
        {
          if(nums[0]==nums[1])
            {
              res.push_back(nums[0]);
              return res;
            }
        }
        int cd1,cd2;
        int cnt1=0,cnt2=0;
        for(int x: nums)
        {
            if(x==cd1)
             cnt1++;
            else if(x==cd2)
             cnt2++;
            else if(cnt1==0)
              {cd1=x; cnt1++;}
            else if(cnt2==0)
              {cd2=x; cnt2++;}
            else 
              {cnt1--; cnt2--;}
        }
        int nc1=0,nc2=0;
        for(int x: nums)
        {
            if(x==cd1) nc1++;
            else if (x==cd2) nc2++;
        }
        if(nc1>(floor(n/3)))
         res.push_back(cd1);
        if(nc2>(floor(n/3)))
         res.push_back(cd2);
        return res;
    }
};