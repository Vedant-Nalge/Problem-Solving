class Solution {
public:
    int helper(int r ,int c ,vector<vector<int>> & dp){
        if(r<0 || c<0) return 0;
        if(r==0 && c==0) return 1;
        
        if(dp[r][c]!=-1) return dp[r][c];

        int left =  helper(r-1,c,dp);

        int top = helper (r,c-1,dp);

        return dp[r][c] = left + top;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp (m+1,vector<int>(n+1,-1));
        return helper(m-1,n-1,dp);

        
    }
};