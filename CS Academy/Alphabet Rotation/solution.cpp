#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include "../prettyprint.h"

using namespace std;

int n;
vector<string> words;

void read() {
    cin >> n;
    words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
}

void solve() {
    unordered_map<string, int> data;
    for (int i = 0; i < n; i++) {
        int word = words[i].length();
        int delta = 26 - (words[i][0] - 'a');
        // apply circular transform, we apply moving everything by 'delta', it's now unrotated
        // i.e. first letter is alwaus 'a', and the rest are in its relative position
        for (int j = 0; j < word; j++) {
            // new relative position
            int curr = words[i][j] - 'a';
            curr = (curr + delta) % 26;
            // update transformed word
            words[i][j] = char('a' + curr);
        }
        ++data[words[i]];
    }
    for (int i = 0; i < n; i++) {
        if (data[words[i]] > 1) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}

int main() {
    read();
    solve();
}