class Solution {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev1=2;
        if(n<=2)
         return n;
        for(int i=3;i<=n;i++)
        {
            int res=prev2+prev1;
            prev2=prev1;
            prev1=res;
        }
        return prev1;
    }
};