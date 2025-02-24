class Solution {
public:
    bool compare(vector<int> mp1,vector<int> mp2){
        for(int i=0;i<26;i++)
        {if(mp1[i]!=mp2[i])
            return false;}
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()){
            return false;
        }
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;
        }
        int left=0,right=s1.length()-1;
        while(right<s2.length()){
            if(compare(mp1,mp2)==true){
                return true;
            }
            mp2[s2[left]-'a']--; 
            left++;
            if(right+1<s2.length())
            mp2[s2[right+1]-'a']++;
            right++;
        }
        return false;
    }
};