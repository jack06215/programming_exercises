#include <vector>
#include <queue>

using namespace std;

/*
given N=3 and K=7

at the 1st level: [1, 2, 3, 4, 5, 7, 8, 9]
at the 2nd level: [18, 29, 70, 81, 92]
at the 3rd level: [181, 292, 707, 818, 929]
*/
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
            for (int j = 0; j < size; j++) {
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