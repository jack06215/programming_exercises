#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    bool check(vector<string>& board, int row, int column) {
        for (int i = row; i >= 0; i--) {
            if (board[i][column] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = column; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void placequeen(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        for (int index = 0; index < board.size(); index++) {
            if (check(board, row, index)) {
                board[row][index] = 'Q';
                placequeen(board, row + 1);
                board[row][index] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        placequeen(board, 0);
        return res.size();

    }
};
