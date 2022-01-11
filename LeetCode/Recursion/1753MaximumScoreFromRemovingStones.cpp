#include <algorithm>

using namespace std;

// ensure a > b > c. Then just pick from a and b and repeat the process resursively
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a < b) {
            return maximumScore(b, c, a);
        }
        if (b < c) {
            return maximumScore(a, c, b);
        }
        if (b == 0) {
            return 0;
        }
        int count = max(1, b - c);
        return count + maximumScore(a - count, b - count, c);
    }
};
