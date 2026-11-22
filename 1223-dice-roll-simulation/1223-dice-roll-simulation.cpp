class Solution {
public:
    int mod = 1e9 +7;
    int helper(int n , int f ,int k , vector<int> & rollMax, vector<vector<vector<int>>> &dp){
         if(n==0) return 1;
         if(dp[n][f][k]!=-1) return dp[n][f][k];
         
         dp[n][f][k] = 0 ;

         for(int i = 0 ; i < 6 ; i++){
            if(i==f){
                if(k<rollMax[i]){
                    dp[n][f][k] = (dp[n][f][k] + helper(n-1,i,k+1,rollMax,dp))% mod;
                }
            }
            else{
                dp[n][f][k] = (dp[n][f][k] + helper(n-1,i,1,rollMax,dp))% mod;
            }
         }



        return dp[n][f][k]%mod;



    }
    int dieSimulator(int n, vector<int>& rollMax) {
        //rolls,prev face, consecutive rolls until prev face
        int f = 6;
        int k = 15;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(f+1,vector<int>(k+1,-1)));
        return helper(n,6,0,rollMax,dp);
        
    }
};