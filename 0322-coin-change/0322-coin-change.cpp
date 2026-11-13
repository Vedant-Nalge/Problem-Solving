class Solution {
public:
    int helper(int i, int k, vector<int>& coins, vector<vector<int>>& dp) {
        if (i < 0 || k < 0)
            return 1e9;
        if (k == 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];

        int nottake = helper(i - 1, k, coins, dp);
        int take = 1e9;
        if (coins[i] <= k)
            take = 1 + helper(i, k - coins[i], coins, dp);

        dp[i][k] = min(take, nottake);
        return dp[i][k];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        // dp[denomi][target]
        int ans = helper(n - 1, amount, coins, dp);
        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};