class Solution {
public:
    void func(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, int i, int n) {
        if (i == n) {
            res.push_back(temp);
            return;
        }

        // include
        temp.push_back(nums[i]);
        func(res, temp, nums, i + 1, n);

        // exclude
        temp.pop_back();
        func(res, temp, nums, i + 1, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        func(res, temp, nums, 0, nums.size());
        return res;
    }
};
