class Solution {
public:
    vector<vector<int>> ans;

    void helper(int i , int target , vector<int> & candidates ,vector<int> &ds){
        if(i>=candidates.size() || target <0) return ;

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        helper(i+1,target,candidates,ds);
    

        if (candidates[i] <= target) {
            ds.push_back(candidates[i]);
            helper(i, target - candidates[i], candidates, ds);
            ds.pop_back(); // Backtrack
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();

        vector<int>ds;

        helper(0,target,candidates,ds);

        return ans;
        
    }
};