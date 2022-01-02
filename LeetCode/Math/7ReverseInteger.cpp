#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        const int maxx = numeric_limits<int>::max() / 10;
        const int minn = numeric_limits<int>::min() / 10;
        while (x) {
            if (res > maxx || res < minn) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
