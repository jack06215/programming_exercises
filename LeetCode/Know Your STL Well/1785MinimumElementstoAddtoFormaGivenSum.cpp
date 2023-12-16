#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

class Solution {
public:
  int minElements(std::vector<int>& nums, int limit, int goal) {
    int64_t diff = std::abs(goal - std::accumulate(begin(nums), end(nums), 0LL));
    return (diff + limit - 1) / limit;
  }
};
