class Solution {
public:
    long long helper(int ind, int k, vector<vector<int>>& dp,
                     vector<int>& coins) {
        if (k == 0)
            return 0;
        if (ind == 0) {
            if (k % coins[ind] == 0)
                return k / coins[ind];
            else
               return  1e9;
        }

        if (dp[ind][k] != -1)
            return dp[ind][k];

        long long nottake = helper(ind - 1, k, dp, coins);
        long long take = 1e9;
        if (coins[ind] <= k)
            take = 1 + helper(ind, k - coins[ind], dp, coins);

        return dp[ind][k] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // variables are coin size , amount
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        long long ans = helper(n - 1, amount, dp, coins);

        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};