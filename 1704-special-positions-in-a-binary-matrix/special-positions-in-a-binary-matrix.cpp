class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        map<int,int> mpr,mpc;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    if(mpr.find(i)==mpr.end())
                     mpr[i]=1;
                    else
                     mpr[i]++;
                    if(mpc.find(j)==mpc.end())
                     mpc[j]=1;
                    else
                     mpc[j]++;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {if(mpr.find(i)==mpr.end())
                 break;
                else if(mpc.find(j)==mpc.end())
                 continue;
                else if(mpr[i]!=1)
                break;
                else if(mpc[j]!=1)
                break;
                else
                {cout<<i<<" "<<j<<" "<<mpr[i]<<" "<<mpc[j]<<endl; cnt++; break;}
                }
            }
        }
        return cnt;
    }
};