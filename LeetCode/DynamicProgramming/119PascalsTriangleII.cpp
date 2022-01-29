#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        row[rowIndex] = 1;
        for (size_t i = 1; i < (row.size() + 1) / 2; ++i) {
            auto val = static_cast<uint64_t>(row[i - 1]) * static_cast<uint64_t>(rowIndex - i + 1) / i;
            row[i] = row[rowIndex - i] = val;
        }
        return row;
    }
};