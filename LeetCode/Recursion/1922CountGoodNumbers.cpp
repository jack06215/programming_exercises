#define MOD 1000000007

using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        // if n is even then no. of even and odd place will be n / 2
        if (n % 2 == 0) {
            return (binaryExp(5, n / 2) % MOD) * (binaryExp(4, n / 2) % MOD) % MOD;
        }
        // else if n is odd then no. of even place will be n/2+1 and odd place will be n/2
        return (binaryExp(5, n / 2 + 1) % MOD) * (binaryExp(4, n / 2) % MOD) % MOD;
    }

    long long binaryExp(long long num, long long pow) {
        if (pow == 1) {
            return num;
        }
        if (pow == 0) {
            return 1;
        }
        long long result = binaryExp(num, pow / 2) % MOD;
        if (pow % 2 == 0) {
            return ((result) * (result)) % MOD;
        }
        else {
            return ((num % MOD) * (((result) * (result) % MOD) % MOD)) % MOD;
        }
    }
};