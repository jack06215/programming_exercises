#include <iostream>

using namespace std;

class LeastCommonMultiple {
private:
    int gcd(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }
        if (a == b) {
            return a;
        }
        if (a > b) {
            return gcd(a - b, b);
        }
        return gcd(a, b - a);
    }
public:
    int solve(int a, int b) {
        return a * b / gcd(a, b);
    }
};

int main() {
    auto s = LeastCommonMultiple();
    cout << s.solve(42, 63) << endl;
    return 0;
}
