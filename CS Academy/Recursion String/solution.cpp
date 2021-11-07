#include <vector>
#include <string>
#include <iostream>

using namespace std;

int n, k;
vector<int> arr(36);

string findKth(int n, int k) {
    if (k > arr[n]) return "-1";
    if (n == 0) return "a";
    if (n == 1) return "b";
    if (n == 2) return "c";

    if (k > arr[n - 1] + arr[n - 2]) {
        return findKth(n - 3, k - arr[n - 1] - arr[n - 2]);
    }

    else if (k > arr[n - 1]) {
        return findKth(n - 2, k - arr[n - 1]);
    }
    else {
        return findKth(n - 1, k);
    }
}

void read() {
    cin >> n >> k;
}

int main() {
    read();

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    for (int i = 3; i <= 36; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    cout << findKth(n, k);
    return 0;
}