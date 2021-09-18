#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int upper_limit = numeric_limits<int>::max() / 10;
        int lower_limit = numeric_limits<int>::min() / 10;
        while(x){
            if(res > upper_limit || res < lower_limit)
                return 0;
            res = res*10 + x%10;
            x /= 10; 
        }
        return res;
    }
};
