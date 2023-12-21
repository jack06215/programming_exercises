#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
private:
    int N;
    vector<int> A;
public:
    Solution() {
        cin >> N;
        A.resize(N);
        for (auto& it : A) {
            cin >> it;
        }
    }

    void solve() {
        vector<int> B(N);
        vector<pair<int, int>> valueIndexPairs(N);

        // Pair each element with its index
        for (int i = 0; i < N; i++) {
            valueIndexPairs[i] = { A[i], i };
        }

        // Sort the pairs
        sort(begin(valueIndexPairs), end(valueIndexPairs));

        // Assign ranks
        int rank = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0 || valueIndexPairs[i].first != valueIndexPairs[i - 1].first) {
                rank++;
            }
            B[valueIndexPairs[i].second] = rank;
        }

        for (int i = 0; i < N; ++i) {
            cout << B[i] << (i < N - 1 ? ' ' : '\n');
        }
    }
};

class Solution2 {
private:
    int N;
    vector<int> A;
public:
    Solution2() {
        cin >> N;
        A.resize(N);
        for (auto& it : A) {
            cin >> it;
        }
    }

    void solve() {
        vector<uint64_t> asor;
        copy(begin(A), end(A), back_inserter(asor));

        sort(asor.begin(), asor.end());
        asor.erase(unique(asor.begin(), asor.end()), asor.end());

        for (int i = 0; i < N; i++) {
            uint64_t left = 1;
            uint64_t right = asor.size();
            while (right > left) { 
                uint64_t mid = (left + right) / 2;

                if (asor[mid - 1] > A[i]) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }

            if (asor[right - 1] > A[i]) {
                cout << right - 1 << " ";
            }
            else {
                cout << right << " ";
            }
        }
    }
};

int main() {
    auto solution = Solution2();
    solution.solve();
}
