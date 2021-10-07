#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

/*
    Assume two points are top-left(x0, y0) and bottom-right(x1, y1), where (x0 != x1) and (y0 != y1)
    The other two points will be (x0, y1), (x1, y0)
*/
class Solution {
public:
  int minAreaRect(vector<vector<int>>& points) {    
    const auto inf = numeric_limits<int>::max();
    const int sz = points.size();
    int min_area = inf;
    
    // INDEX: x-coord
    // VALUE: list of unique (x, y1), (x, y2)..., coords
    unordered_map<int, unordered_set<int>> combs;
    for (const auto& point : points) {
        combs[point[0]].insert(point[1]);
    }

    // go through all combinations
    for (int i = 0; i < sz; ++i) {
        for (int j = i + 1; j < sz; ++j) {
            // grab two points (x0, y0), (x1, y1)
            // assuming it's top-left and bottom-right
            int x0{ points[i][0] }, y0{ points[i][1] };
            int x1{ points[j][0] }, y1{ points[j][1] };
            
            // we cannot form rectangle when two points are 
            // aligned either vertically or horizontally
            if (x0 == x1 || y0 == y1) continue;

            // calcuate the area and skip if it is not minimum
            int area = abs(x0 - x1) * abs(y0 - y1);
            if (area > min_area) continue;
            
            // since we only take two points, we need to
            // ensure the top-right and bottom-left exists
            // i.e. (x0, y1), (x1, y0)
            // otherwise it is still invalid
            if (!combs[x1].count(y0) || !combs[x0].count(y1)) continue;
            
            // all criteria are met, assigned the new minimum area
            min_area = area;
        }
    }
    return min_area == inf ? 0 : min_area;
  }
};
