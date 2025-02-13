class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mini,maxi;
        int res=0;
        int start=0,end=prices.size()-1;
        int c=prices[0],d=prices[end];
        for(int i=0;i<prices.size();i++){
            c=min(c,prices[i]);
            mini.push_back(c);
        }
        for(int i=prices.size()-1;i>=0;i--){
            d=max(d,prices[i]);
            maxi.push_back(d);
        }
        reverse(maxi.begin(),maxi.end());
        for(int i=start;i<=end;i++){
            res=max(res,maxi[i]-mini[i]);
        }
        return res;
        
    }
};