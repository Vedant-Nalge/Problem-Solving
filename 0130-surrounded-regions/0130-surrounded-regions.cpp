class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue <pair<int, int>> q;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        // we will cover all borders and secure them ,and then secure all the
        // nodes which are connected to border
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }
            if (board[i][m - 1] == 'O') {
                board[i][m - 1] = '#';
                q.push({i, m - 1});
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }
            if (board[n - 1][j] == 'O') {
                board[n - 1][j] = '#';
                q.push({n - 1, j});
            }
        }

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = a + dr[i];
                int nc = b + dc[i];

                if (nr >= 0 && nc >= 0 && nr<n && nc<m && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};