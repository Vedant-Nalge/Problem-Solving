class Solution {
public:
    int helper(int i, int prev, vector<vector<int>>& pairs, vector<vector<int>>& dp) {
        if (i >= pairs.size()) return 0;
        
        // Offset prev by +1 to handle -1 initial index safely
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        // Option 1: Skip current pair
        int notTake = helper(i + 1, prev, pairs, dp);

        // Option 2: Take current pair (if valid)
        int take = 0;
        if (prev == -1 || pairs[prev][1] < pairs[i][0]) {
            take = 1 + helper(i + 1, i, pairs, dp);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        
        // dp[i][prev+1]
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, pairs, dp);
    }
};