#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> stk;
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && T[stk.top()] < T[i]) {
                int j = stk.top();
                stk.pop();
                res[j] = i - j;
            }
            stk.push(i);
        }
        return res;
    }
};
