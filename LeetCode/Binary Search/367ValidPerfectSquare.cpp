#include <cstdint>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        while (left <= right) {
            uint64_t mid = left + (right - left) / 2;
            uint64_t squared = mid * mid;
            if (squared == num) {
                return true;
            }
            else if (squared > num) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};
