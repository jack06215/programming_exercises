#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

/*
    Getting the previous level value and storing it in prev variable
    And then calculating the current level values based on previous level values
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        ans.reserve(numRows);
        helper(numRows);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> helper(int n) {
        if (n == 1) {
            ans.push_back({ { 1 } });
            return ans[n - 1];
        }
        if (n == 2) {
            helper(n - 1);
            ans.push_back({ { 1, 1 } });
            return ans[n - 1];
        }
        vector<int> prev = helper(n - 1);
        vector<int> temp(n, 1);
        for (int i = 1; i < n - 1; i++) {
            temp[i] = prev[i] + prev[i - 1];
        }
        ans.push_back(temp);
        return temp;
    }
};

class Solution {
public:
    vector<vector<int>> pascal;

    vector<int> getVector(vector<int>& vec, vector<int>& preVec, int i) {
        // vector are filled, we can return
        if (i == preVec.size()) {
            return vec;
        }
        // fill new element
        vec[i] = preVec[i - 1] + preVec[i];
        // fill the rest of elements (++i means fill next element)
        return getVector(vec, preVec, ++i);
    }
    vector<vector<int>> makeTriangle(int n, int n_rols) {
        if (n == n_rols) {
            return pascal;
        }
        // initializing the first and last elements of the vector to be added
        vector<int> new_row(n + 1, 0);
        new_row[0] = 1;
        new_row[n] = 1;

        // gets the vector
        pascal.push_back(getVector(new_row, pascal[n - 1], 1));
        // make the next row (++n for 1 step deeper)
        return makeTriangle(++n, n_rols);
    }
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return pascal;
        }
        else if (numRows == 1) {
            return { {1} };
        }
        else if (numRows == 2) {
            return { {1},{1,1} };
        }
        // base case
        pascal = { {1},{1,1} };
        // complete the rest of triangle
        return makeTriangle(2, numRows);
    }
};

int main(int argc, char const* argv[]) {
    cout << Solution().generate(10) << endl;
    return 0;
}
