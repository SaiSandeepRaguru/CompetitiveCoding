class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp,mp2;
        for(int x: arr2){
            if(mp.find(x)!=mp.end()){
                mp[x]=1;
                mp2[x]=0;
            }
            else{
                mp[x]++;
            }
        }
        vector<int> temp;
        for(int x: arr1){
            if(mp.find(x)==mp.end()){
                temp.push_back(x);
            }
            else{
                mp2[x]++;
            }
        }
        vector<int> res;
        for(int x: arr2){
            int ct = mp2[x];
            for(int i=0;i<ct;i++){
                res.push_back(x);
            }
        }
        sort(temp.begin(),temp.end());
        for(int x: temp){
            res.push_back(x);
        }
        return res;   
    }
};