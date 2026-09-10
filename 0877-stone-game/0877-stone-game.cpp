class Solution {
public:
    int helper(int f, int l, vector<int>& piles, vector<vector<int>>& dp) {
        if (f > l)
            return 0;

        if (dp[f][l] != -1)
            return dp[f][l];

        int le = piles[f] - helper(f + 1, l, piles, dp);
        int r = piles[l] - helper(f, l - 1, piles, dp);

        dp[f][l] = max(le, r);
        return dp[f][l];
    }
    bool stoneGame(vector<int>& piles) {
        // we will track alice number of stones ,if it is positve then alice
        // wins
        int n = piles.size();
        // track ind and sum;
        vector<vector<int>> dp (n+1,vector<int>(n+1,-1));
        return (helper(0, n - 1, piles, dp) > 0);
    }
};