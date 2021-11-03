#include <iostream>
#include <cctype>

using namespace std;

int64_t N, M, X, Y;

void read() {
    cin >> N >> M >> X >> Y;
}

bool check(int64_t nums_evolve) {
    if (nums_evolve <= N && (M + (N - nums_evolve) * Y) >= nums_evolve * X) {
        return true;
    }
    return false;
}

void solve() {
    int64_t low = 0;
    int64_t high = N;
    while (low < high) {
        int64_t mid = (low + high + 1) / 2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low << endl;
}

int main() {
    read();
    solve();
    return 0;
}

// #include <iostream>
// #include <cctype>

// using namespace std;

// int N, M, X, Y;

// void read() {
//     cin >> N >> M >> X >> Y;
// }

// bool check(int m) {
//     if (m <= N && (M + (N - m) * Y) >= m * X) {
//         return true;
//     }
//     return false;
// }

// void solve() {
//     int low = 0;
//     int high = N;
//     while (low < high) {
//         int mid = low + (high - low) / 2;
//         if (check(mid + 1)) {
//             low = mid + 1;
//         }
//         else {
//             high = mid;
//         }
//     }
//     cout << low << endl;
// }

// int main() {
//     read();
//     solve();
//     return 0;
// }