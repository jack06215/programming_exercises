#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        else if (x < 3) return 1;
        
        uint64_t left = 0;
        uint64_t right = x;
        
        uint64_t result;
        while (left <= right) {
            uint64_t mid = (left + right) / 2;
            uint64_t squared = mid * mid;
            if (squared == x) {
                return mid;
            }
            else if (squared < x) {
                left = mid + 1;
                result = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return result;
    }
};