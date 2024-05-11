class Solution {
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) {
                return false;
            }
            if (board[i][col] == ch) {
                return false;
            }
            // Reason why do we this type of indexing-
            // + i / 3 and + i % 3, increment the index while keeping it 
            // within the subgrid 
            // 3 * (row / 3) and 3 * (col / 3) makes the index such that it iterates
            // from the start of that grid irrespective of which row and column, they
            // initially belonged to. 
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch) {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};