#include <vector>
#include <unordered_set>
#include <limits>
#include <algorithm>
#include <iostream>
#include <string>
#include "../MurmurHash2.h"
#include "../prettyprint.h"

namespace std {
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const noexcept {
            return hash<long long>()(((long long)v.first)^(((long long)v.second) << 32));
        }
    };
}
using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<pair<int, int>> seen;
        const auto inf = numeric_limits<int>::max();
        int res = inf;
        for (const auto& p : points) {
            int x1{p[0]}, y1{p[1]};
            for (auto[x2, y2] : seen) 
                if (seen.count({x1, y2}) && seen.count({x2, y1})) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    res = min(area, res);
                }
            seen.emplace(x1, y1);
        }
        cout << seen << endl;
        return res == inf ? 0 : res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
    cout << s.minAreaRect(points) << endl;
    return 0;
}

