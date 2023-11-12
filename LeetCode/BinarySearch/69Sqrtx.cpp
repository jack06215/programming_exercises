#include <cstdint>
#include <iostream>

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

        uint64_t left = 1;
        uint64_t right = x;

        while (left < right) {
            uint64_t mid = left + (right - left) / 2;
            uint64_t squared = mid * mid;
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

int main() {
    auto s = Solution();
    cout << s.mySqrt(2147395599) << endl;
    return 0;
}
