#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // base case
        if (rowIndex == 0) {
            return { 1 };
        }

        vector<int> curRow = { 1 };
        vector<int> prevRow = getRow(rowIndex - 1);

        // fill the current row based on previous row
        for (int i = 1; i < rowIndex; i++) {
            curRow.push_back(prevRow[i - 1] + prevRow[i]);
        }

        // fill the last element of current row
        curRow.push_back(1);
        return curRow;
    }
};
