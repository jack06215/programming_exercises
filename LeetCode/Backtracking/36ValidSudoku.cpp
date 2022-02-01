#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9);
        vector<set<int>> cols(9);
        vector<set<int>> blocks(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // 0  0  0  1  1  1  2  2  2  
                // 0  0  0  1  1  1  2  2  2
                // 0  0  0  1  1  1  2  2  2
                // 3  3  3  4  4  4  5  5  5
                // 3  3  3  4  4  4  5  5  5
                // 3  3  3  4  4  4  5  5  5
                // 6  6  6  7  7  7  8  8  8
                // 6  6  6  7  7  7  8  8  8  
                // 6  6  6  7  7  7  8  8  8
                int n = (i / 3) * 3 + j / 3;

                // skip if it's empty
                if (board[i][j] == '.') {
                    continue;
                }

                // any of these conditions satisfied will mean it's an invalid sudoku
                int curr = board[i][j] - '0';
                if (rows[i].count(curr) || cols[j].count(curr) || blocks[n].count(curr)) {
                    return false;
                }

                // update lookup table
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[n].insert(curr);
            }
        }
        return true;
    }
};