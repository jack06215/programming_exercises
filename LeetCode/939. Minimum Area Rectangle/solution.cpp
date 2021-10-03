#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minAreaRect(vector<vector<int>>& points) {    
    unordered_map<int, unordered_set<int>> s;
    for (const auto& point : points) {
        s[point[0]].insert(point[1]);
    }
    const auto inf = numeric_limits<int>::max();
    const int n = points.size();
    int min_area = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x0{points[i][0]}, y0{points[i][1]};
            int x1{points[j][0]}, y1{points[j][1]};
            if (x0 == x1 || y0 == y1) continue;

            int area = abs(x0 - x1) * abs(y0 - y1);
            if (area > min_area) continue;
            if (!s[x1].count(y0) || !s[x0].count(y1)) continue;
            min_area = area;
        }
    }
    return min_area == inf ? 0 : min_area;
  }
};
