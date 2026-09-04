class Solution {

public:
    int helper(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];

        int take = 0;
        int nottake = helper(ind + 1, prev, nums, dp);

        if (prev == -1 || nums[ind] % nums[prev] == 0) {
            take = 1 + helper(ind + 1, ind, nums, dp);
        }

        return dp[ind][prev + 1] = max(take, nottake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        helper(0, -1, nums, dp);
        vector<int> ans;
        int prev = -1;
        for (int ind = 0; ind < n; ind++) {

            if (prev == -1 || nums[ind] % nums[prev] == 0) {

                int take = 1 + helper(ind + 1, ind, nums, dp);

                int notTake = helper(ind + 1, prev, nums, dp);
                if (take >= notTake && dp[ind][prev + 1] == take) {

                    ans.push_back(nums[ind]);

                    prev = ind;
                }
            }
        }

        return ans;
    }
};