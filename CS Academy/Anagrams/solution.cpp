#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// variables
vector<string> words;
int n;

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        words.push_back(word);
    }
}

void solve() {
    for (auto& word : words) {
        sort(word.begin(), word.end());
    }
    unordered_map<string, int> wordFreq;
    int best = 0;
    for (const auto& word : words) {
        wordFreq[word] += 1;
        best = max(best, wordFreq[word]);
    }
    cout << best << "\n";
}

int main() {
    read();
    solve();
    return 0;
}