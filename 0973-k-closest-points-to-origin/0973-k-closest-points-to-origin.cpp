class Solution {
public:
    double dist(int x1, int y1) { return sqrt(x1 * x1 + y1 * y1); }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;

        for (auto it : points) {
            int x1 = it[0];
            int y1 = it[1];
            double d = dist(x1, y1);
            pq.push({d, {x1, y1}});
        }
        while (k > 0) {
            auto it = pq.top();
            int x1 = it.second.first;
            int y1 = it.second.second;
            pq.pop();
            ans.push_back({x1, y1});
            k--;
        }
        return ans;
    }
};