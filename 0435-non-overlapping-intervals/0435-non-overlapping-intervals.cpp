class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int let = intervals[0][1];

        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= let) {
                cnt++;
                let = intervals[i][1];
            }
        }

        return n - cnt;
    }
};