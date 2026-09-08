class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row) {
        int freq[10] = {0};
        for (int i = 0; i < board.size(); i++){
            if (board[row][i] == '.') continue;
            freq[board[row][i] - '0']++;
            if (freq[board[row][i] - '0'] > 1)
                return false;
        }
        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col) {
        int freq[10] = {0};
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == '.') continue;
            freq[board[i][col] - '0']++;
            if (freq[board[i][col] - '0'] > 1)
                return false;
        }
        return true;
    }

    bool isValidBox(vector<vector<char>>& board, int row, int col) {
        int freq[10] = {0};
        for (int i = row; i < row + 3; i ++)
            for (int j = col; j < col + 3; j ++) {
                if (board[i][j] == '.') continue;
                freq[board[i][j] - '0']++;
                if (freq[board[i][j] - '0'] > 1)
                    return false;
            }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        for (int row = 0; row < 9 && valid; row ++) {
            if (!isValidRow(board, row))
                valid = false;
        }

        for (int col = 0; col < 9 && valid; col ++) {
            if (!isValidCol(board, col))
                valid = false;
        }

        for (int row = 0; row < 9 && valid; row += 3)
            for (int col = 0; col < 9 && valid; col += 3) {
                if (!isValidBox(board, row, col))
                    valid = false;
            }

        return valid;
    }
};