#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n;
    int x;
    vector<int> A;

public:
    Solution() {
        cin >> n >> x;
        A.resize(1010);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
    }

    void solve() {
        for (int i = 0; i < n; ++i) {
            if (A[i] == x) {
                cout << "Yes" << endl;
                return;
            }
        }
        cout << "No" << endl;
        return;
    }
};

int main() {
    auto s = Solution();
    s.solve();
    return 0;
}