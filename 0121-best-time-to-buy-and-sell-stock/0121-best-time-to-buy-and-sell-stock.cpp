class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         int maxpro = 0;
         int mini = INT_MAX;
         for(int i =0;i<n;i++){
            mini = min(mini,prices[i]);
            maxpro = max(maxpro,prices[i]-mini);
         }
        
        return maxpro;
    }
};