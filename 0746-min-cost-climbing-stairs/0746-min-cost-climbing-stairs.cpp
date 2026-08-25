class Solution {
public:
    int helper(int ind ,vector<int>& cost,vector<int> &dp){
        if(ind<0) return 0;
        if(ind ==0 || ind ==1) return 0;
        if(dp[ind]!=-1 ) return dp[ind];
        int jump1 = cost[ind-1] + helper(ind-1,cost,dp);
        int jump2 = INT_MAX;
        if(ind > 1) 
         jump2 = cost[ind-2] + helper(ind-2,cost,dp);

         return dp[ind]= min(jump1,jump2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);

        return helper(n,cost,dp);

        
    }
};