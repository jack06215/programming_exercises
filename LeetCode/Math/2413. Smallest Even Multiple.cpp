class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }
public:
    int smallestEvenMultiple(int n) {
        return n * 2 / gcd(n, 2);
    }
};
