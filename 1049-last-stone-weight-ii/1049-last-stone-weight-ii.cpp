class Solution {
public:
    int helper(int i, int target, vector<int>& stones,
               vector<vector<int>>& dp) {
        if (i < 0 || target == 0)
            return 0;
        if (dp[i][target] != -1)
            return dp[i][target];

        int take = 0;
        if (target >= stones[i])
            take = stones[i] + helper(i - 1, target - stones[i], stones, dp);
        int nottake = helper(i - 1, target, stones, dp);

        return dp[i][target] = max(take, nottake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int sum = 0;
        for (auto it : stones) {
            sum += it;
        }
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int subset_sum = helper(n - 1, target, stones, dp);

        return sum - 2 * subset_sum;
    }
};