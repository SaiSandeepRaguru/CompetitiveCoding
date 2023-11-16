class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        int n = nums[0].size();

        string res(n, '0');
        for (int i = 0; i < n; ++i) {
            res[i] = (nums[0][i] == '0') ? '1' : '0';
        }

        while (s.find(res) != s.end()) {
            for (int i = n - 1; i >= 0; --i) {
                if (res[i] == '0')
                    res[i] = '1';
                else
                    res[i] = '0';
                if (res[i] == '1') break;
            }
        }

        return res;
    }
};
