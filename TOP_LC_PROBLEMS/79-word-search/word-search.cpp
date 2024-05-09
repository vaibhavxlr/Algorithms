class Solution {
    bool solve(vector<vector<char>>& board, int rs, int cs, string& word,
               int index) {
        if (word.size() == index) {
            return true;
        }

        if (rs < 0 || cs < 0 || rs >= board.size() || cs >= board[0].size()) {
            return false;
        }

        if (board[rs][cs] == ' ' || board[rs][cs] != word[index]) {
            return false;
        }

        char temp = board[rs][cs];
        board[rs][cs] = ' ';
        bool incl = solve(board, rs - 1, cs, word, index + 1) ||
                    solve(board, rs, cs + 1, word, index + 1) ||
                    solve(board, rs, cs - 1, word, index + 1) ||
                    solve(board, rs + 1, cs, word, index + 1);
        board[rs][cs] = temp;

        return incl;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};