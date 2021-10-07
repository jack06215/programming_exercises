#include <vector>

// class Solution {
// public:
//     std::vector<int> twoSum(std::vector<int>& numbers, int target) {
//         int head = 0;
//         int tail = numbers.size() - 1;
        
//         while (head <= tail) {
//             if (numbers[head] + numbers[tail] == target) {
//                 return { head + 1, tail + 1 };
//             }
//             else if (numbers[head] + numbers[tail] < target) {
//                 head++;
//             }
//             else {
//                 tail--;
//             }
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int res = numbers[left] + numbers[right];
            if (res == target) {
                return { left + 1, right + 1 };
            }
            else if (res > target) {
                right--;
            }
            else {
                left++;
            }
        }
        return {};
    }
};
