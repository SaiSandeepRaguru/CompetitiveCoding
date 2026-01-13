class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int len = s.length();
        int start = 0, end = 0, maxi = 0;
        for (; end < len; end++) {
            mp[s[end]]++;
            while (mp[s[end]]>1) {
                mp[s[start]]--;
                start++;
            }
            maxi = max(maxi, end - start + 1);
        }
        return maxi;
    }
};