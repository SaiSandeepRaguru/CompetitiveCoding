class Solution {
public:
    bool compare(map<char,int> mp1,map<char,int> mp2){
        for(auto i=mp1.begin();i!=mp1.end();i++){
            if(mp2.find(i->first)==mp2.end() || mp2[i->first]!=mp1[i->first])
            return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()){
            return false;
        }
        map<char,int> mp1,mp2;
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        int left=0,right=s1.length()-1;
        while(right<s2.length()){
            if(compare(mp1,mp2)==true){
                return true;
            }
            mp2[s2[left]]--; 
            if(mp2[s2[left]]==0){
                mp2.erase(s2[left]);
            }
            left++;
            if(right+1<s2.length())
            mp2[s2[right+1]]++;
            right++;
        }
        return false;
    }
};