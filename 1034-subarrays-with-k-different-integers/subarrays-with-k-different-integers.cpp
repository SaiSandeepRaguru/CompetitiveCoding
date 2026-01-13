class Solution {
public:
    int countOfDistinctWithLessThanEqualK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int, int> mp;
        for (; right < nums.size(); right++) {
            mp[nums[right]]++;
            while (mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            count += (right - left) + 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countOfDistinctWithLessThanEqualK(nums, k) -
               countOfDistinctWithLessThanEqualK(nums, k - 1);
    }
};