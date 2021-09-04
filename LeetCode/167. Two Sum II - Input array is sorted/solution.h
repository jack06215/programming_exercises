#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int head = 0;
        int tail = numbers.size() - 1;
        
        while (head <= tail) {
            if (numbers[head] + numbers[tail] == target) {
                return { head + 1, tail + 1 };
            }
            else if (numbers[head] + numbers[tail] < target) {
                head++;
            }
            else {
                tail--;
            }
        }
        return {};
    }
};