class Solution {
public:
    int lengthOfPalindrome(string s,int p,int q){
        while(p>=0 && q<s.length() && s[p]==s[q]){
            p--; q++;
        }
        return (q-p-1); //since q and p did not match,p+1 and q-1 are part of palindrome
    }
    string longestPalindrome(string s) {
        int left=0,right=0;
        for(int i=0;i<s.length();i++){
            int len1=lengthOfPalindrome(s,i,i);
            int len2=lengthOfPalindrome(s,i,i+1);
            int len = max(len1,len2);
            if(len>right-left+1){
                left=i-len/2;
                right=i+len/2;
                if(len%2==0){
                    left++;
                }
            }
        }
        return s.substr(left,right-left+1);
    }
};