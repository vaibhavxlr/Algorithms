class Solution {
    vector<vector<string>> sol;
    
    bool isValid(vector<string>& board, int row, int col) {
        for(int i = row; i < board.size(); i++) 
            if(board[i][col] == 'Q') {
                return false;
            } 

        int newRow = row;
        int newCol = col;
        
        while(newRow < board.size() && newCol < board.size()) {
            if(board[newRow][newCol] == 'Q') {
                return false;
            }
            newRow++;
            newCol++;
        }

        newRow = row;
        newCol = col;
        while(newRow < board.size() && newCol >= 0) {
            if(board[newRow][newCol] == 'Q') {
                return false;
            }
            newRow++;
            newCol--;
        }
        return true;
    } 

    void solve(vector<string>& board, int row) {
        if(row < 0) {
            sol.push_back(board);
            return;
        }
        for(int j = 0; j < board.size(); j++) {
            if(isValid(board, row, j)) {
                board[row][j] = 'Q';
                solve(board, row - 1);
                board[row][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int row = n - 1;

        // As we know, there will be 1 Queen in each row and column,
        // we can keep row constantly decreasing and iterate over
        // all columns to get all the possibilities, effectively getting rid of nested loops.
        solve(board, row);
        return sol;        
    }
};