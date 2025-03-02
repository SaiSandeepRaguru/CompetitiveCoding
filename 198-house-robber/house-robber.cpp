class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if(n==1){
            return a[0];
        }
        int prev2=0,prev1=0,res=0;
        for(int x: a){
            res=max(prev2+x,prev1);
            prev2=prev1;
            prev1=res;
        }
        return res;
    }
};