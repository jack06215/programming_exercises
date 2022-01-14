#include <vector>
#include <queue>

using namespace std;

class Solution {
    const int MAX_N = 9;
    const int MAX_K = 9;
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        vector<int> res;
        for (int i = 1; i <= MAX_N; i++) {
            q.push(i);
        }

        for (int i = 1; i < n; i++) {
            int size = q.size();
            for (int i = 0;i < size; i++) {
                int num = q.front();
                q.pop();
                int last_digit = num % 10;
                if (last_digit + k <= MAX_K) {
                    q.push(num * 10 + last_digit + k);
                }
                if (last_digit - k >= 0 && k != 0) {
                    q.push(num * 10 + last_digit - k);
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};