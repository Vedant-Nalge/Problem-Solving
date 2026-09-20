class Solution {
public:
    int helper(int ind, vector<int>& points, vector<int>& dp) {
        if (ind <= 0)
            return 0;
        if (ind == 1)
            return points[1];
        if (dp[ind] != -1)
            return dp[ind];

        int take = points[ind] + helper(ind - 2, points, dp);
        int nottake = helper(ind - 1, points, dp);

        return dp[ind] = max(take, nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            points[nums[i]] += nums[i];
        }
        vector<int> dp(maxi + 1, -1);
        return helper(maxi, points, dp);
    }
};