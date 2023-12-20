#include <iostream>

using namespace std;

class Solution {
private:
    int n;
public:
    Solution() {
        cin >> n;
    }

    void solve() {
        cout << n * n << endl;
    }
};

int main() {
    auto s = Solution();
    s.solve();
    return 0;
}