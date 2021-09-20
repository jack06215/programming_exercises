#include <iostream>

using namespace std;

class Solution {
public:
    long long power(long long x, long long y, long long p = 1000000007)
    {
        long long res = 1;
        x = x % p;
        if (x == 0) 
            return 0;
 
        while (y > 0) {
            if (y & 1) {
                res = (res * x) % p;
            }
            y >>= 1;
            x = (x * x) % p;
        }
        return res;
    }
    
    long long countGoodNumbers(long long n) {
        // 5 possibles for even digit, 4 possibles odd digit
        long long even = power(5, (n + 1) / 2);
        long long odd = power(4, n / 2);
        cout << even << " " << odd << endl;
        long long ans = (even * odd) % 1000000007;
        return ans;
        
        
    }
};
