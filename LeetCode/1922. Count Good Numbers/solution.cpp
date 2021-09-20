#include <iostream>

using namespace std;

class Solution {
public:
    long long modpow(long long base, long long exp, long long modulus){
        long long result = 1;
        // long long y = base; 
        while (exp > 0) {
            if (exp & 1) { // odd exponent
                result = (result * base) % modulus; // multiplying with base
            }
            base = (base * base) % modulus; // squaring the base
            exp >>= 1;
        }
        return result % modulus;
    }
    
    long long countGoodNumbers(long long n) {
        // 5 possibles for even digit, 4 possibles odd digit
        // => 5^n_even * 4^n_odd
        long long even = modpow(5, (n + 1) / 2, 1000000007);
        long long odd = modpow(4, n / 2, 1000000007);
        cout << even << " " << odd << endl;
        long long ans = (even * odd) % 1000000007;
        return ans; 
    }
};
