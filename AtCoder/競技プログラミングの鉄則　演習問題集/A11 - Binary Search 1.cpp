#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int N;
    int X;
    vector<int> A;

public:
    Solution() {
        cin >> N >> X;
        A.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
    }

    void solve() {
        int left = 0;
        int right = A.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == X) {
                cout << mid + 1 << endl;
                return;
            }
            else if (A[mid] < X) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
    }
};

int main() {
    auto solution = Solution();
    solution.solve();
    return 0;
}