class Solution {
public:
    void func(vector<vector<int>>& res, vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            func(res, nums, i + 1);
            swap(nums[i], nums[j]);  // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        func(res, nums, 0);
        return res;
    }
};
