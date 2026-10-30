class Solution {
public:
    bool helper(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        
        if (target == 0) return true;
        if (i < 0 || target < 0) return false;
        
        
        if (dp[i][target] != -1) return dp[i][target];
        
       
        bool take = helper(i - 1, target - nums[i], nums, dp);
        
        
        bool nottake = helper(i - 1, target, nums, dp);
        
        return dp[i][target] = (take || nottake);
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(n - 1, target, nums, dp);
    }
};