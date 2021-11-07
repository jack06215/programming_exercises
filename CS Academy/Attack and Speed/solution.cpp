#include <iostream>
#include <algorithm>

using namespace std;

int A, S;
int K;
int X, Y;

void read() {
    cin >> A >> S >> K >> X >> Y;
}

int calc(int gem) {
    return (A + gem * X) - (S + (K - gem) * Y);
}

void solve() {
    int left = 0;
    int right = K + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int target = calc(mid);
        if (target == 0) {
            cout << mid;
            return;
        }
        else if (target > 0) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << -1;
    return;
}

int main() {
    read();
    solve();
    return 0;
}