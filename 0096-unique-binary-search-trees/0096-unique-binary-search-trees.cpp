class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];

        dp[n] = 0;
        for (int i = 1; i <= n; i++) {
            dp[n] += helper(i - 1, dp) * helper(n - i, dp);
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};