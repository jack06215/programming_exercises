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
    int newA = (A + gem * X);
    int newS = (S + (K - gem) * Y);
    return newA - newS;
}

void solve() {
    int left = 0;
    int right = K + 1;
    while (left < right) {
        // using 'mid' gem, can we make it balance?
        int mid = left + (right - left) / 2;
        // by balance, we mean the target value is 0
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