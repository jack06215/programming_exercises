/*
    A 個白球
    B 個紅球
    C 個黑球

    任意挑 K 個，列出所有不同組合

    將答案表示成 [白色個數, 紅色個數, 黑色個數] 如下:

    [
        [4,0,0],
        [3,1,0],
        [3,0,1],
        [2,2,0],
        ...
    ]
*/
#include <vector>
#include <iostream>
#include <unordered_set>
#include "prettyprint.h"

using namespace std;

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

int a, b, c, k;
vector<vector<int>> res;

void helper(vector<int>& balls, unordered_set<vector<int>, VectorHash>& seen, int& cnt) {
    cnt++;
    int sum = 0;
    for (int i = 0; i < balls.size(); i++) {
        if (balls[i] < 0) {
            return;
        }
        sum += balls[i];
    }
    if (sum == k && seen.find(balls) == seen.end()) {
        res.push_back(balls);
        seen.insert(balls);
        return;
    }

    for (int i = 0; i < balls.size(); i++) {
        balls[i]--;
        helper(balls, seen, cnt);
        balls[i]++;
    }
}

void read() {
    cin >> a >> b >> c >> k;
}

void solve() {
    int count = 0;
    int* p_count = &count;
    vector<int> balls = { a, b, c };
    unordered_set<vector<int>, VectorHash> seen;
    helper(balls, seen, count);
    cout << count << endl;
}

int main(int argc, char const* argv[]) {
    read();
    solve();
    cout << res << endl;
    return 0;
}
