#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// variables
vector<int> A;
int n, k;

// read input function
void read() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        A.push_back(num);
    }
}

// solver function
void solve() {
    sort(A.begin(), A.end());
    int counter = ((A[1] - A[0]) > k) + ((A[n - 1] - A[n - 2]) > k);
    for (int i = 1; i < n - 1; i++) {
        counter += (A[i + 1] - A[i]) > k && (A[i] - A[i - 1]) > k;
    }
    cout << counter << endl;
}

int main() {
    read();
    solve();
    return 0;
}

