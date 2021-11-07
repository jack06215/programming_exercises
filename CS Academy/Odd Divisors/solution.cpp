#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

uint64_t A, B, T;

void read() {
    cin >> T;
}

uint64_t solve(uint64_t N) {
    if (N <= 0) {
        return 0;
    }
    uint64_t K = (N / 2) + (N % 2);
    return K * K + solve(N / 2);
}

int main() {
    read();
    while (T--) {
        cin >> A >> B;
        cout << solve(B) - solve(A - 1) << endl;
    }
}
