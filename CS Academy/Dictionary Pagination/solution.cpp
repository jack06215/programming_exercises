#include <map>
#include <iostream>
#include <sstream>
#include "../prettyprint.h"
#include "input.h"

using namespace std;

int n, q, x;
string w;
map<string, int> mp;

istringstream ss(input1);

void read() {
    ss >> n >> q;
    for (int i = 0; i < n; i++) {
        string s;
        ss >> s;
        mp[s]++;
    }
}

void solve() {
    int count = 0; 
    for (auto item : mp) {
        count += item.second;
        mp[item.first] = count;
    }
    cout << mp << endl;
    for (int i = 0; i < q; i++) {
        ss >> w >> x;
        if (mp[w] % x == 0) {
            cout << mp[w] / x << endl;
        }
        else {
            cout << mp[w] / x + 1 << endl;
        }
    }
    cout << endl;
}

int main() {
    read();
    solve();
    return 0;
}