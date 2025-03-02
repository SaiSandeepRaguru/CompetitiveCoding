class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        if(n==2){
            return min(a[0],a[1]);
        }
        int first=a[0],second=a[1],res=0;
        for(int i=2;i<n;i++){
            res=a[i]+min(first,second);
            first=second;
            second=res;
        }
        return min(first,second);
    }
};