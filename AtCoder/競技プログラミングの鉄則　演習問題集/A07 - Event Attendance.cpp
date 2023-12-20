#include <iostream>
#include <vector>
#include "prettyprint.h"

using namespace std;

class Solution1 {
private:
    int D, N;
    vector<int> L;
    vector<int> R;

public:
    Solution1() {
        cin >> D >> N;
        L.resize(N);
        R.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> L[i] >> R[i];
        }
    }

    void solve() {
        vector<int> res(D + 1, 0);
        for (int i = 0; i < N; i++) {
            int start = L[i];
            int end = R[i];
            for (int j = start; j <= end; j++) {
                res[j]++;
            }
        }
        for (int i = 1; i <= D; i++) {
            cout << res[i] << endl;
        }
    }
};

class Solution2 {
private:
    int D, N;
    vector<int> L;
    vector<int> R;

public:
    Solution2() {
        cin >> D >> N;
        L.resize(N);
        R.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> L[i] >> R[i];
        }
    }

    void solve() {
        vector<int> changes(D + 1, 0);
        for (int i = 0; i < N; ++i) {
            changes[L[i]] += 1;
            changes[R[i] + 1] -= 1;
            cout << changes << endl;
        }

        for (int i = 1; i <= D; ++i) {
            changes[i] += changes[i - 1];
        }

        for (int i = 1; i <= D; ++i) {
            cout << changes[i] << endl;
        }
    }
};

int main() {
    auto s = Solution2();
    s.solve();
    return 0;
}
