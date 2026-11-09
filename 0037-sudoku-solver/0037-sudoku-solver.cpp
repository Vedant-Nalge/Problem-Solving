class Solution {
private:
    bool backtrack(int cellIndex, vector<vector<char>>& board, 
                   const vector<pair<int, int>>& emptyCells,
                   vector<vector<bool>>& rowUsed,
                   vector<vector<bool>>& colUsed,
                   vector<vector<vector<bool>>>& blockUsed) {
        
        // Base case: all empty cells have been filled
        if (cellIndex == emptyCells.size()) {
            return true;
        }

        int r = emptyCells[cellIndex].first;
        int c = emptyCells[cellIndex].second;

        for (int digit = 0; digit < 9; ++digit) {
            if (!rowUsed[r][digit] && !colUsed[c][digit] && !blockUsed[r / 3][c / 3][digit]) {
                // Place character
                board[r][c] = digit + '1';
                rowUsed[r][digit] = true;
                colUsed[c][digit] = true;
                blockUsed[r / 3][c / 3][digit] = true;

                // Recurse to next empty cell
                if (backtrack(cellIndex + 1, board, emptyCells, rowUsed, colUsed, blockUsed)) {
                    return true;
                }

                // Backtrack (undo state)
                board[r][c] = '.';
                rowUsed[r][digit] = false;
                colUsed[c][digit] = false;
                blockUsed[r / 3][c / 3][digit] = false;
            }
        }

        return false; // Triggers backtracking step
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> emptyCells;
        vector<vector<bool>> rowUsed(9, vector<bool>(9, false));
        vector<vector<bool>> colUsed(9, vector<bool>(9, false));
        vector<vector<vector<bool>>> blockUsed(3, vector<vector<bool>>(3, vector<bool>(9, false)));

        // Pre-fill lookup states and collect empty cell positions
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    emptyCells.push_back({r, c});
                } else {
                    int digit = board[r][c] - '1';
                    rowUsed[r][digit] = true;
                    colUsed[c][digit] = true;
                    blockUsed[r / 3][c / 3][digit] = true;
                }
            }
        }

        // Start recursion from the 0th empty cell
        backtrack(0, board, emptyCells, rowUsed, colUsed, blockUsed);
    }
};