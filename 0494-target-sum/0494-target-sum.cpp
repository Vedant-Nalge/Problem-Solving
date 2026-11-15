class Solution {
public:
    int helper(int i, int t, vector<int>& nums, vector<vector<int>>& dp) {
       if (i == 0) {
            if (t == 0 && nums[0] == 0)
                return 2;
            if (t == 0 || t == nums[0])
                return 1;
            return 0;
        }
        if (dp[i][t] != -1)
            return dp[i][t];

        int nottake = helper(i - 1, t, nums, dp);
        int take = 0;
        if (nums[i] <= t)
            take = helper(i - 1, t - nums[i], nums, dp);

        return dp[i][t] = take + nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums)
            sum += x;
        if (abs(target) > sum )
            return 0;
        if ((sum - target) % 2 != 0)
            return 0;
        int k = (sum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return helper(n - 1, k, nums, dp);
    }
};