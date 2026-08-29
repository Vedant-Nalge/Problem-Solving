class Solution {
public:
    int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

        if (ind == 0) {
            if (target == 0 && arr[0] == 0)
                return 2;

            if (target == 0 || arr[0] == target)
                return 1;

            return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];

        int nottake = solve(ind - 1, target, arr, dp);

        int take = 0;

        if (arr[ind] <= target) {
            take = solve(ind - 1, target - arr[ind], arr, dp);
        }

        return dp[ind][target] = take + nottake;
    }

    int countPartitions(int n, int diff, vector<int>& arr) {

        int totalSum = 0;

        for (int x : arr) {
            totalSum += x;
        }

        if (abs(diff) > totalSum)
            return 0;

        if ((totalSum - diff) % 2 != 0)
            return 0;

        int K = (totalSum - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(K + 1, -1));

        return solve(n - 1, K, arr, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};