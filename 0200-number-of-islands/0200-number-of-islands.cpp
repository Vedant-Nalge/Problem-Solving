class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == '1' && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};