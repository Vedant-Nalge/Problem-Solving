class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid,
            vector<vector<bool>>& visited) {
        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        int area = 1;
        while (!q.empty()) {
            auto node = q.front();
            int r = node.first;
            int c = node.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 &&
                    nc < m && !visited[nr][nc]&& grid[nr][nc] == 1) {
                    visited[nr][nc] = true;
                    area++;
                    q.push({nr, nc});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    visited[i][j] = true;
                    maxi = max(maxi, bfs(i, j, grid, visited));
                }
                else continue;
            }
        }
        return maxi;
    }
};