class Solution {

public:
    int helper(int ind, int target, vector<int>& nums, vector<vector<int>>& dp,
               int offset) {
        if (ind == 0) {

            if (nums[0] == target && nums[0] == -target)
                return 2;

            if (nums[0] == target || nums[0] == -target)
                return 1;

            return 0;
        }
        if (abs(target) > offset)
            return 0;

        if (dp[ind][target + offset] != -1)
            return dp[ind][target + offset];

        int plus = helper(ind - 1, target - nums[ind], nums, dp, offset);
        int minus = helper(ind - 1, target + nums[ind], nums, dp, offset);

        return dp[ind][target + offset] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;

        for (int x : nums) {
            sum += x;
        }
        int offset = sum;

        if (abs(target) > sum)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return helper(n - 1, target, nums, dp, offset);
    }
};