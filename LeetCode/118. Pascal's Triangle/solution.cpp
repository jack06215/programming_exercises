#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return { {1} };
        }

        // reserve just enough space to create triangle
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
        // flush array before creating a new one
        vector<int> res;

        // 1st element is always 1
        res.push_back(1);

        // get previous row
        vector<int> prev_row = result[row - 1];

        // starting from index 1, we add up two numbers
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

int main(int argc, char const* argv[]) {
    Solution s;
    cout << s.generate(20) << endl;
    return 0;
}
