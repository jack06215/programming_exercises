#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascals(numRows);
        for (int i = 0; i < numRows; i++) {
            pascals[i].resize(i + 1);
            pascals[i][0] = 1;
            pascals[i][i] = 1;
            for (int j = 1; j < i; j++)
                pascals[i][j] = pascals[i - 1][j - 1] + pascals[i - 1][j];
        }
        return pascals;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return { {1} };
        }
        result.reserve(numRows);

        // base case
        result.push_back({ 1 });
        result.push_back({ 1, 1 });

        for (int i = 2; i < numRows; ++i) {
            result.push_back(make_new_row(i));
        }
        return result;
    }

    vector<int> make_new_row(int row) {
        vector<int> res;
        // 1st element is always 1
        res.push_back(1);
        auto prev_row = result[row - 1];

        for (int i = 1; i < row; ++i) {
            int current = prev_row[i - 1] + prev_row[i];
            res.push_back(current);
        }

        // last element is always 1
        res.push_back(1);
        return res;
    }

private:
    vector<vector<int>> result;
};
