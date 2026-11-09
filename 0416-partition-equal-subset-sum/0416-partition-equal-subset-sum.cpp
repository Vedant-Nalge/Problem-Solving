class Solution {
public:
    bool helper(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (i < 0 || target < 0)
            return false;
        if(target==0) return true;
        if (dp[i][target] != -1)
            return dp[i][target];
        bool take = false;
        bool nottake = helper(i - 1, target, nums, dp);
        if (nums[i] <= target) {
            take = helper(i - 1, target - nums[i], nums, dp);
        }
        return dp[i][target] =take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }

        if (sum % 2 != 0)
            return false;
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));

        return helper(n - 1, sum / 2, nums, dp);
    }
};