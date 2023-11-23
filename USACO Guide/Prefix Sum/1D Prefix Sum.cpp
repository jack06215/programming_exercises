#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    int N, Q;
    vector<int> a;
    vector<pair<int, int>> queries;
    vector<int> prefixSum(const vector<int>& a) {
        vector<int> psum(size(a) + 1);
        for (int i = 0; i < size(a); ++i) {
            psum[i + 1] = psum[i] + a[i];
        }
        // partial_sum(begin(a), end(a), begin(psum) + 1);
        return psum;
    }
public:
    Solution() {
        cin >> N >> Q;
        a.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        queries.resize(Q);
        for (int i = 0; i < Q; ++i) {
            cin >> queries[i].first >> queries[i].second;
        }
    }

    void solve() {
        vector<int> p = prefixSum(a);
        for (int i = 0; i < Q; ++i) {
            int l, r;
            tie(l, r) = queries[i];
            cout << p[r] - p[l] << "\n";
        }
    }
};

int main() {
    auto solution = Solution();
    solution.solve();
}