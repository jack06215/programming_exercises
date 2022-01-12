#include <vector>
#include <unordered_set>
#include <limits>
#include <iostream>
#include <string>

using namespace std;

struct hasher {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<pair<int, int>, hasher> seen;
        const auto inf = numeric_limits<int>::max();
        int res = inf;
        for (const auto& p : points) {
            int x1 = p[0];
            int y1 = p[1];
            for (auto [x2, y2] : seen) {
                if (seen.count({ x1, y2 }) && seen.count({ x2, y1 })) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    res = min(area, res);
                }
            }
            seen.emplace(x1, y1);
        }
        return res == inf ? 0 : res;
    }
};
