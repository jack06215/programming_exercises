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
            ans.push_back(vector<int> { 1 });
            return ans[n - 1];
        }
        if (n == 2) {
            helper(n - 1);
            ans.push_back(vector<int> { 1, 1 });
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

int main(int argc, char const *argv[]) {
    cout << Solution().generate(10) << endl;
    return 0;
}
