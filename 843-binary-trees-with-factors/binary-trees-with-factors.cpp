class Solution {
public:
    const int MOD = 1000000007;

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, long long> dp;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            dp[arr[i]] = 1;  // Initialize with a single node tree
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int quotient = arr[i] / arr[j];
                    if (dp.find(quotient) != dp.end()) {
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[quotient]) % MOD;
                    }
                }
            }
            ans = (ans + dp[arr[i]]) % MOD;
        }

        return ans;
    }
};
