class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(); // lower - nums[i] <=  <= lower - nums[j]
        for (int i = 0; i < n; i++) {
            int upper_diff = upper - nums[i];
            int lower_diff = lower - nums[i];
            auto l = lower_bound(nums.begin() + i + 1, nums.end(), lower_diff);
            auto u = upper_bound(nums.begin() + i + 1, nums.end(), upper_diff);

            ans += u - l;
        }
        return ans;
    }
};