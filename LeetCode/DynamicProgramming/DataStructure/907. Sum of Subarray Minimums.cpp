#include <vector>
#include <stack>
#include <iostream>
#include <cstdint>

#include "../../codec.h"
#include "../../prettyprint.h"

using namespace std;

class Solution {
    int64_t MOD = 1000000007;
public:
    int sumSubarrayMins(vector<int>& A) {
        const int n = A.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<pair<int, int>> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int len = 1;
            while (!s.empty() && s.top().first > A[i]) {
                len += s.top().second; s.pop();
            }
            s.emplace(A[i], len);
            left[i] = len;
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; --i) {
            int len = 1;
            while (!s.empty() && s.top().first >= A[i]) {
                len += s.top().second; s.pop();
            }
            s.emplace(A[i], len);
            right[i] = len;
        }
        cout << left << endl;
        cout << right << endl;
        for (int i = 0; i < n; ++i) {
            ans = (ans + static_cast<long>(left[i]) * A[i] * right[i]) % MOD;
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    auto arr = stringToIntVector("[3,1,2,4]");
    cout << Solution().sumSubarrayMins(arr) << endl;

    return 0;
}
