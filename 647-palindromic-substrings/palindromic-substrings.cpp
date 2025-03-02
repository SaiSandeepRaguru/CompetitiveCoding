class Solution {
public:
    int lengthOfPalindrome(string s,int p,int q){
        int count=0;
        while(p>=0 && q<s.length() && s[p]==s[q]){
            p--; q++; count++;
        }
        return count; 
    }
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.length();i++){
            int count1=lengthOfPalindrome(s,i,i);
            int count2=lengthOfPalindrome(s,i,i+1);
            res+=count1+count2;
        }
        return res;
    }
};