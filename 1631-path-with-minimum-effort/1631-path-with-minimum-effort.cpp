class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        pq.push({0,{0,0}});
            dis[0][0] = 0;

            while (!pq.empty()) {
                auto node = pq.top();
                pq.pop();
                int diff = node.first;
                int r = node.second.first;
                int c = node.second.second;

                if (r == n - 1 && c == m - 1)
                    return diff;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        int neweffort =
                            max(diff, abs(heights[r][c] - heights[nr][nc]));
                        if (neweffort < dis[nr][nc]){
                                dis[nr][nc] = neweffort;
                                pq.push({neweffort, {nr, nc}});
                            }
                    }
                }
            }
            return 0;
    }
    };