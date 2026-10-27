class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (auto it : intervals) {
            // if ans is empty or if the pervious end time is less than the next
            // start time ,insert the nee interval
            if (ans.size() == 0 || ans.back()[1] < it[0]) {
                ans.push_back(it);
            }
            // merge them and the end time will be the maximum of both end times
            else {
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }

        return ans;
    }
};