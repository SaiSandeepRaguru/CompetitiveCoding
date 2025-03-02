class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if(n==1){
            return a[0];
        }
        if(n==2){
            return max(a[0],a[1]);
        }
        if(n==3){
            return max(a[0]+a[2],a[1]);
        }
        int first=a[0],second=a[1],third=a[0]+a[2],res=max(first,max(second,third));
        for(int i=3;i<n;i++){
            int temp = a[i]+max(first,second);
            first=second;
            second=third;
            third=temp;
            res=max(res,temp);
        }
        return res;
    }
};