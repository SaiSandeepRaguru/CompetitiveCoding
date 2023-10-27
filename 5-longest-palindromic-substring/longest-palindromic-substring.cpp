class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1)
         return s;
        bool table[n][n];
        int max_length=0;
        string maxi="";
        memset(table,false,sizeof(table));
        for(int i=0;i<n;i++)
        {
            table[i][i]=true;
            if(max_length<1)
            {maxi=maxi+s[i]; max_length=1;}
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {table[i][i+1]=true; 
             if(max_length<2)
              {max_length=2; maxi=s.substr(i,2);}
            }
        }
        for(int k=3;k<=n;k++) //note here k<=n
        {
            for(int i=0;i<n-k+1;i++) //note here i<n-k+1
            {
                int j=i+k-1;
                if(table[i+1][j-1]==true && s[i]==s[j])
                {
                    table[i][j]=true;
                    if(max_length<k)
                    {max_length=k; maxi=""+s.substr(i,k);}
                }

            }
        }
        return maxi;
    }
};