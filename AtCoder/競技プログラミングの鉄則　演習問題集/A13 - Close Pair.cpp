#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int N;
    uint64_t K;
    vector<uint64_t> A;
public:
    Solution() {
        cin >> N >> K;
        A.resize(N);
        for (auto& it : A) {
            cin >> it;
        }
    }

    void solve() {
        uint64_t count = 0;
        int j = 0;
        for (int i = 0; i < N; i++) {
            while (j < N && A[j] - A[i] <= K) {
                j++;
            }
            count += j - i - 1;
        }

        cout << count << endl;
    }
};

int main() {
    auto solution = Solution();
    solution.solve();
    return 0;
}
