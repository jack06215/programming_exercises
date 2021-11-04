#include <vector>
#include <iostream>

using namespace std;

int n, k;
vector<int> dominoes;

void read() {
    cin >> n >> k;
    dominoes.resize(n);
}

int main() {
    read();
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i];
    }
    int left = k;
    int right = n + k + 1;
    int ans = 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        bool isSatisfy = false;
        for (int i = 1; i <= dominoes.back(); i++) {
            // find range
            int a = lower_bound(dominoes.begin(), dominoes.end(), i + mid) - dominoes.begin();
            int b = lower_bound(dominoes.begin(), dominoes.end(), i) - dominoes.begin();
            
            int len = a - b;
            // Can we fill gaps (i.e. making it consecutive) using k 
            if (mid <= k + len) {
                isSatisfy = true;
                break;
            }
        }
        if (isSatisfy) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    cout << ans << "\n";
    return 0;
}