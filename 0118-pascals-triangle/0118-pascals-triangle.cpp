class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& dp) {
        if (j == 0 || j == i) {
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = helper(i - 1, j - 1, dp) + helper(i - 1, j, dp);
        return dp[i][j];
    }
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans(n);
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            ans[i].resize(i + 1);
            for (int j = 0; j <= i; j++) {
                ans[i][j] = helper(i, j, dp);
            }
        }
        return ans;
    }
};