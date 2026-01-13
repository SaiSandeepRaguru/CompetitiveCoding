class Solution {
public:
    bool hasSubstring(unordered_map<char, int>& mp1,
                      unordered_map<char, int>& mp2) {
        for (auto& p : mp1) {
            char x = p.first;
            if (mp2.find(x) == mp2.end() || mp2[x] < mp1[x]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int start = 0, end = 0;
        int ansstart = -1, ansend = -1, len = INT_MAX;
        unordered_map<char, int> mp1, mp2;
        for (char c : t) {
            mp1[c]++;
        }
        for (; end < s.length(); end++) {
            mp2[s[end]]++;
            while (hasSubstring(mp1, mp2)) {
                int count = end - start + 1;
                if (len > count) {
                    len = count;
                    ansstart = start;
                    ansend = end;
                }
                mp2[s[start]]--;
                if (mp2[s[start]] == 0) {
                    mp2.erase(s[start]);
                }
                start++;
            }
        }
        return len == INT_MAX ? "" : s.substr(ansstart, len);
    }
};