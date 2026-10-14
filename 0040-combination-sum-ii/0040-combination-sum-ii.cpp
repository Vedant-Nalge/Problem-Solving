class Solution {
public:
    void helper(int ind, int k, vector<int>& candidates, vector<int>& curr,
                vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(curr);
            return;
        }
        if (ind < 0 || k < 0)
            return;

        curr.push_back(candidates[ind]);

        helper(ind - 1, k - candidates[ind], candidates, curr, ans);
        curr.pop_back();

        while (ind > 0 && candidates[ind] == candidates[ind - 1]) {
            ind--;
        }
        helper(ind - 1, k, candidates, curr, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates.size() - 1, target, candidates, curr, ans);

        return ans;
    }
};