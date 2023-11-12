#include <vector>
#include <string>


using namespace std;

class Solution {
private:
    int width;
    int height;
    bool checkWordPresent(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index == word.size()) {
            return true;
        }
        if (row < 0 || col < 0 || row >= height || col >= width || board[row][col] != word[index]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '*';
        bool ans1 = checkWordPresent(board, word, row + 1, col, index + 1);
        bool ans2 = checkWordPresent(board, word, row, col + 1, index + 1);
        bool ans3 = checkWordPresent(board, word, row - 1, col, index + 1);
        bool ans4 = checkWordPresent(board, word, row, col - 1, index + 1);
        board[row][col] = temp;
        return ans1 || ans2 || ans3 || ans4;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        height = board.size();
        width = board[0].size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (checkWordPresent(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
