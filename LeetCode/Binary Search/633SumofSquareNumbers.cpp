#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 3) {
            return true;
        }
        int low = 0;
        int hi = sqrt(c);
        while (low <= hi) {
            int guess = c - hi * hi;
            if (guess == low * low) {
                return true;
            }
            else if (guess < low * low) {
                hi--;
            }
            else {
                low++;
            }
        }
        return false;
    }
};
