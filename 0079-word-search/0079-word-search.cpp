class Solution {
public:
    bool helper(int r, int c, vector<vector<char>>& board, string& word, vector<vector<bool>> &visited, int index) {
                    
        int n = board.size();
        int m = board[0].size();
        if(index == word.size()) return true;
        if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] ||
            board[r][c] != word[index])
            return false;

        visited[r][c] = true;
        bool found = helper(r - 1, c, board, word, visited, index + 1) ||
                     helper(r + 1, c, board, word, visited, index + 1) ||
                     helper(r, c - 1, board, word, visited, index + 1) ||
                     helper(r, c + 1, board, word, visited, index + 1);

        visited[r][c] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (helper(i, j, board, word, visited, 0))
                    return true;
            }
        }
        return false;
    }
};