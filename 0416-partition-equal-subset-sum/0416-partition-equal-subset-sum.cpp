class Solution {
public:
    bool helper(int ind,int target,vector<vector<int>> &dp,vector<int> & nums){
        if(target == 0) return true;

        if(ind ==0) return bool(nums[ind] == target);

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool notpick = helper(ind-1,target,dp,nums);
         bool pick =false;

         if(nums[ind]<=target) pick = helper(ind-1,target - nums[ind],dp,nums);

         return dp[ind][target]= pick || notpick;
    }
     
    bool subsetsum(vector<int>&nums,int target){
        int n = nums.size();
        vector<vector<int>> dp (n,vector<int>(target+1,-1));

        return helper(n-1,target,dp,nums);



    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum =0;

        for(int i =0 ;i<n;i++){
            sum+=nums[i];

        }

        if(sum%2!=0) return false;

        else return subsetsum(nums,sum/2);
        
    }
};