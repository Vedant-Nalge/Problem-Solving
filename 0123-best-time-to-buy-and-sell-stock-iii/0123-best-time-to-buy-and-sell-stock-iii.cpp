class Solution {
public:
    int helper(int ind, int buy, int cap, vector<int>& prices,
               vector<vector<vector<int>>>& dp) {
        if (ind == prices.size() || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit = 0;

        if (buy == 0) {
            profit =
                max(0 + helper(ind + 1, 0, cap, prices, dp),
                    -prices[ind] + helper(ind + 1, 1, cap, prices, dp));
        }

        if (buy == 1) {
            profit = max(0 + helper(ind + 1, 1, cap, prices, dp),
                         prices[ind] + helper(ind + 1, 0, cap - 1, prices, dp));
        }

        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp( n, vector<vector<int>>(2, vector<int>(3, -1)));

        return helper(0, 0, 2, prices, dp);
    }
};