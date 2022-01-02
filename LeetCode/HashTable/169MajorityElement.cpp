#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq_count;
        for (auto val : nums) {
            freq_count[val]++;
        }
        auto most_freq = std::max_element(
            freq_count.begin(), freq_count.end(),
            [](const auto& x, const auto& y) { return x.second < y.second; });
        return most_freq->first;
    }
};
