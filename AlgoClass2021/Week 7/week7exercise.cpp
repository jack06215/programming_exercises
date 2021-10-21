#include <iostream>
#include <vector>
#include <stack>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int sz = prices.size();
        vector<int> res(sz);
        vector<int> stk;
        for (int i = 0; i < sz; ++i) {
            while (!stk.empty() && prices[i] < prices[stk.back()]) {
                res[stk.back()] = prices[i];
                stk.pop_back();
            }
            stk.push_back(i);
        }
        cout << res << endl;
        for (int i = 0; i < sz; ++i) {
            res[i] = prices[i] - res[i];
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int>
    return 0;
}
