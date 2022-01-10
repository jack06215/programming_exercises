#include <cstdint>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        else if (x <= 3) {
            return 1;
        }

        int left = 1;
        int right = x;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int squared = mid * mid;
            if (squared == x) {
                return mid;
            }
            else if (squared > x) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};
