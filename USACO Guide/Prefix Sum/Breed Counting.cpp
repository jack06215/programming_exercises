#include <iostream>
#include <vector>
#include "../prettyprint.h"

using namespace std;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=572
class Solution {
private:
    int N, Q;
    vector<int> breeds;
    vector<pair<int, int>> queries;
public:
    Solution() {
        cin >> N >> Q;
        breeds.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> breeds[i];
        }
        queries.resize(Q);
        for (int i = 0; i < Q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
    }
    void solve() {
        vector<vector<int>> prefixSum(4, vector<int>(N + 1, 0));

        // Reading cow breeds and updating prefix sums
        for (int i = 1; i <= N; i++) {
            int breed = breeds[i];

            // Update all bread count previous to i
            for (int j = 1; j <= 3; ++j) {
                prefixSum[j][i] = prefixSum[j][i - 1];
            }

            // Update breed count for i
            prefixSum[breed][i]++;
        }


        // Processing queries
        for (int i = 0; i < Q; i++) {
            int a, b;
            tie(a, b) = queries[i];
            for (int j = 1; j <= 3; j++) {
                cout << prefixSum[j][b] - prefixSum[j][a - 1] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    auto solution = Solution();
    solution.solve();

    return 0;
}
