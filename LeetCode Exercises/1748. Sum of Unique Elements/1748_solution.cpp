#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include "../prettyprint.h"

class Solution {
public:
    int sumOfUnique(std::vector<int>& nums) {
        std::unordered_map<int, int> frequency;
        for (auto val: nums) {
            frequency[val]++;
        }
        return std::accumulate(begin(frequency), end(frequency), 0, [](int sum, const auto& p){
            return sum + (p.second == 1 ? p.first : 0);
        });
    }
};

int main() {
    std::vector<int> input;
    Solution s = Solution();

    input = {1,2,3,2};
    std::cout << s.sumOfUnique(input) << std::endl;

    return 0;
}