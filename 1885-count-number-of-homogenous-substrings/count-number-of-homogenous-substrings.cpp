class Solution {
public:
    long mod=1000000007;
    long long func(int x)
    {
        long long ans=0;
        for(int i=1;i<=x;i++)
        ans=((ans%mod)+(i%mod))%mod;
        return ans;
    }
    int countHomogenous(string s) {
        int n=s.size();
        int i=0;
        int count=0,j=1;
        for(j=1;j<n;j++)
        {
            if(s[j]==s[i])
            {continue;}
            else
            {
                count=(count+(func(j-i)%mod))%mod;
                i=j;
            }
        }
        if(j==n)
        count=(count+(func(j-i)%mod))%mod;
        return count;
    }
};