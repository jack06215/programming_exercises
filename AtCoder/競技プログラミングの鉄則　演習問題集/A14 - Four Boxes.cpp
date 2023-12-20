#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int N, K;
    vector<int> A, B, C, D;
public:
    Solution() {
        cin >> N >> K;
        A.resize(N);
        B.resize(N);
        C.resize(N);
        D.resize(N);
        for (int& a : A) {
            cin >> a;
        }
        for (int& b : B) {
            cin >> b;
        }
        for (int& c : C) {
            cin >> c;
        }
        for (int& d : D) {
            cin >> d;
        }
    }

    void solve() {
        vector<int> sumsAB;
        for (int a : A) {
            for (int b : B) {
                sumsAB.push_back(a + b);
            }
        }

        sort(sumsAB.begin(), sumsAB.end());

        bool found = false;
        for (int c : C) {
            for (int d : D) {
                // Use binary search to find if the complement of c + d exists in sumsAB
                int target = K - (c + d);
                if (binary_search(begin(sumsAB), end(sumsAB), target)) {
                    found = true;
                    break;
                }
            }
        }

        cout << (found ? "Yes" : "No") << endl;
    }
};

int main() {
    auto solution = Solution();
    solution.solve();

    return 0;
}
